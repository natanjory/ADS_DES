clc; clear all; close all;
A = importdata('Gerado_Arrival.txt');
D = importdata('Gerado_Departure.txt');

popFila_filaSize = importdata('popFila_filaSize.txt');
popFila_simTime = importdata('popFila_simTime.txt');
pushFila_filaSize = importdata('pushFila_filaSize.txt');
pushFila_simTime = importdata('pushFila_simTime.txt');


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

interval=500;
subplot(2,1,2)
plot(popFila_simTime,popFila_filaSize);
grid on;
title('Apos retirar da Fila')
xlabel('tempo de simulacao')
ylabel('tamanho da fila')
xlim([0,interval])
ylim([-1,max(pushFila_filaSize)+1])
subplot(2,1,1)
stairs(pushFila_simTime,pushFila_filaSize);
xlabel('tempo de simulacao')
ylabel('tamanho da fila')
title('Apos colocar na fila')
ylim([-1,max(pushFila_filaSize)+1])
grid on;
xlim([0,interval])