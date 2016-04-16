%% Clear command window and workspace

clc;
clear;
 
%% Define variables
 
% J
energy_Out = 4.32e11;
% m/s^2
gravity = 9.81;
% kg/m^3
pWater = 1000;
 
%% Prompt user input

np = input('\nEnter the pump efficiency: ');
nt = input('Enter the turbine efficiency: ');
pipeDiam = input('Enter the pipe diameter (m): ');
pipeLen = input('Enter the pipe length (m): ');
pipeFric = input('Enter the pipe friction factor: ');
resDepth = input('Enter the reservoir depth (m): ');
botElev = input('Enter the elevation of bottom of resevoir (m): ');
qPump = input('Enter the volumetric flow rate of pump (m^3/sec): ');
qTurbine = input('Enter the volumetric flow rate of turbine (m^3/sec): ');
bendCo1 = input('Enter the first bend coefficient: ');
bendCo2 = input('Enter the second bend coefficient: ');
 
%% Caclulations 
%J
Et_Loss = energy_Out * ((1 / nt) - 1); 
Ewater_Bt = energy_Out + Et_Loss;
%J
Ebend2 = bendCo2 * Ewater_Bt;
Ewater_Bt2 = Ewater_Bt + Ebend2;
%J
Epipe_Loss = Ewater_Bt * (pipeFric * pipeLen / pipeDiam);
Epipe = Ewater_Bt2 + Epipe_Loss;
%J
Ebend1 = bendCo1 * Ewater_Bt;
EwBB1 = Epipe + Ebend1;

ERloss = 0; % Energy loss from the reservoir = 0
EwR = EwBB1; % Energy inside the reservoir
%kg
mass = EwR / (gravity * (botElev + (resDepth / 2)));
%m^3
volume = mass / pWater;
%m^2
surfArea = volume / resDepth;
% seconds
timeEmpt = volume / qTurbine; 
timeFill = volume / qPump; 
% J
kEDown = (EwR / (2 * gravity * botElev + resDepth / 2)); 
kEDown = kEDown * (qPump / ((pipeDiam ^ 2) / 4 * pi)) ^ 2;
%J
ElossB1 = kEDown * bendCo1;
EwBB1 = EwR + ElossB1;
%J
ElossP = kEDown * pipeFric * pipeLen / pipeDiam;
EwBP = EwBB1 + ElossP;
%J
ElossB2 = kEDown * bendCo2;
EwBB2 = EwR + ElossB2;
%J
ElossPump = EwBB2 * (-1 + 1 / np);
energy_In = ElossPump + EwBB2;
sysEffic = energy_Out / energy_In;

%% Output

fprintf('\nThe reservoir surface area is %.3f m^2.\n', surfArea);
fprintf('The time to fill the reservoir is %.2f hours.', timeFill / 3600)
fprintf('\nThe time to empty the reservoir is ')
fprintf('%.2f hours.\n', timeEmpt / 3600);
fprintf('The input Energy is %.2f MWh.\n', energy_In * 2.7777 / 10 ^ 10);
fprintf('The system efficiency is %.2f\n', sysEffic);
