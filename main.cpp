#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include<cmath>
#include <queue>
#include "rngExp.h"
#include <fstream>

#define T_MAX 1000
#define SeedA 235
#define SeedS 21
#define mean_processing 0.5
#define mean_arrival 1

using namespace std;

queue<double> myqueue;

enum estado {
    IDLE, BUSY
};

estado server_state = IDLE;
int queue_counter = 0;
double sim_time = 0.0;
double last_event_time = 0.0;
double cumulated_queue_length;
double busy_time_total = 0;

void update_statistics() {
    double time_since_last_event = sim_time - last_event_time;
    cumulated_queue_length += myqueue.size() * time_since_last_event;
    if (server_state == BUSY)
        busy_time_total += time_since_last_event;
}

void dataSave(string nome, double valor) {
    ofstream myfile;
    myfile.open(nome.c_str(), std::ios::app);
    myfile << valor << endl;
    myfile.close();

}

int main(int argc, char** argv) {

    double waiting_time_queue_total = 0.0;
    double next_departure = HUGE_VAL;
    double next_arrival;
    double t;

    rngExp *rng1 = new rngExp(SeedA);
    rngExp *rng2 = new rngExp(SeedS);

    /* ofstream myfile;
     myfile.open ("geracao.txt");
  
     for( int a = 0; a < 10000; a = a + 1 ) {
     myfile << rng1->exp(10)<<endl;
   }
  
     myfile.close();
     */

    remove("Gerado_Departure.txt");
    remove("Gerado_Arrival.txt");

    while (sim_time < T_MAX) {

        if (next_arrival < next_departure) {
            sim_time = next_arrival;
        } else {
            sim_time = next_departure;
        }
        update_statistics();


        if (next_arrival < next_departure) {
            if (server_state == IDLE) {
                server_state = BUSY;
                double gerado = rng2->exp(mean_processing);
                dataSave("Gerado_Departure.txt", gerado);
                next_departure = sim_time + gerado;
            } else {
                myqueue.push(sim_time);
            }
            double gerado_arrival = rng1->exp(mean_arrival);
            dataSave("Gerado_Arrival.txt", gerado_arrival);
            next_arrival = sim_time + gerado_arrival;
        } else {
            if (myqueue.empty()) {
                server_state = IDLE;
                next_departure = HUGE_VAL;
            } else {
                t = myqueue.front();
                //   waiting_time_queue_total+=t;
                myqueue.pop();
                double gerado2 = rng2->exp(mean_processing);
                dataSave("Gerado_Departure.txt", gerado2);
                next_departure = sim_time + gerado2;
                queue_counter++;
                waiting_time_queue_total += sim_time - t;

            }
        }
        last_event_time = sim_time;
    }

    // at the end of the simulation:

    double avg_queue_length = cumulated_queue_length / sim_time;
    double avg_utilization = busy_time_total / sim_time;
    double avg_waiting_time_queue = waiting_time_queue_total / queue_counter;
    cout<<"Resultados para simulação com SeedA="<<SeedA<<"; SeedS="<<SeedS<<":"<<endl<<endl;
    cout << "avg_queue_length: " << avg_queue_length << endl;
    cout << "avg_utilization: " << avg_utilization << endl;
    cout << "avg_waiting_time_queue: " << avg_waiting_time_queue << endl;

    return 0;
}



