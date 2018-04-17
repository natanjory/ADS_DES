
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include<cmath>
#include <queue>
#include "rngExp.h"
#include <fstream>

#define T_MAX 10000

using namespace std;

queue<double> myqueue;
 
enum estado{IDLE, BUSY};

estado server_state= IDLE;
int queue_counter = 0;
double sim_time = 0.0;
double last_event_time = 0.0;
double cumulated_queue_length;
double busy_time_total;

void update_statistics() {
    double time_since_last_event = sim_time - last_event_time;
    cumulated_queue_length += myqueue.size() * time_since_last_event;
    if (server_state == BUSY)
        busy_time_total += time_since_last_event;
}

int main(int argc, char** argv) {
	double lambda1=3;
	double lambda2=5;
	double mean_processing=1/lambda2;
	double mean_arrival=1/lambda1;
	
    

    double waiting_time_total = 0.0;

    double next_departure = HUGE_VAL;
    double next_arrival;
    double t;
    
    rngExp *rng1= new rngExp(15);
    rngExp *rng2= new rngExp(15);
    
 //    cout<<rng1->exp(10)<<" , "<<rng1->exp(10)<<" , " << rng1->exp(10)<<endl ;
 //    cout<<rng2->exp(10)<<" , "<<rng2->exp(10)<<" , " << rng2->exp(10)<<endl ;
 
 ofstream myfile;
  myfile.open ("geracao.txt");
  
  for( int a = 0; a < 10000; a = a + 1 ) {
  myfile << rng1->exp(10)<<endl;
}
  
  myfile.close();
 
 
 
 /*
    while
        (sim_time < T_MAX) {
        if (next_arrival < next_departure)
            sim_time = next_arrival;
        else
            sim_time = next_departure;
		update_statistics();
        if (next_arrival < next_departure) {
            if (server_state == IDLE) {
                server_state = BUSY;
                next_departure = sim_time + rng2->exp(mean_processing);
            } else {
                myqueue.push(sim_time);
            }
			next_arrival = sim_time + rng1->exp(mean_arrival);
        } else {
            if (myqueue.empty()) {
                server_state = IDLE;
                next_departure = HUGE_VAL;
            } else {
                t = myqueue.front();
                myqueue.pop();
                next_departure = sim_time + rng2->exp(mean_processing);
                queue_counter++;
				waiting_time_total = sim_time - t;
			
            }
        }
        last_event_time = sim_time;
    }


    // at the end of the simulation:

	double avg_queue_length = cumulated_queue_length / sim_time;
    double avg_utilization = busy_time_total / sim_time;
    //double man_waiting_time_queue= waiting_time_queue_total/queue_counter;
cout<< avg_queue_length<<"    "<<avg_utilization<<endl;
*/
    return 0;
}



