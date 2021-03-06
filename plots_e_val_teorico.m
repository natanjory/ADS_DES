clc; clear all; close all;
A = importdata('Gerado_Arrival.txt');
D = importdata('Gerado_Departure.txt');

Fila_filaSize = importdata('Fila_filaSize.txt');
Fila_simTime = importdata('Fila_simTime.txt');


subplot(2,1,1);
[h,centers]=hist(A,250);
h=h./length(h);
bar(centers,h/trapz(centers, h))
title(' Distribuicao entre requisicoes');

subplot(2,1,2);
[h2,centers2]=hist(D,250);
h2=h2./length(h2);
bar(centers2,h2/trapz(centers2, h2))
title(' Distribuicao entre serviCos');

figure()
interval=200;
stairs(Fila_simTime,Fila_filaSize);
grid on;
title('Status da fila')
xlabel('tempo de simulacao')
ylabel('tamanho da fila')
xlim([0,interval])
ylim([-1,8])

%% Calculo dos valores teoricos

lamb=1;
u=2;
p=lamb/u;

%a utilizacao  do  sistema
U = p

%numero medio  da requisicoes na fila;
E_Nq=p^2/(1-p)

%tempo  medio na  fila
E_Wq=p/(u - lamb)
