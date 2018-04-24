clc; clear all; close all;
A = importdata('Gerado_Arrival.txt');
D = importdata('Gerado_Departure.txt');

subplot(2,1,1);
[h,centers]=hist(A,250);
h=h./length(h);
bar(centers,h/trapz(centers, h))
title(' Distribuição entre requisições');

subplot(2,1,2);
[h2,centers2]=hist(D,250);
h2=h2./length(h2);
bar(centers2,h2/trapz(centers2, h2))
title(' Distribuição entre serviços');
