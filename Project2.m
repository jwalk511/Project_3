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

%% Calculations
pipeArea = (pipeDiam / 2)^2 * pi;
velocityD = qTurbine / pipeArea;
velocityU = qPump / pipeArea;

mass = (energy_Out + energy_Out*(1/nt - 1)) / ((gravity *... 
(botElev + resDepth/2)) - (pipeFric * pipeLen * velocityD^2 /... 
(2 * pipeDiam)) - (bendCo2 * velocityD^2 / 2));

timeEmpty = mass / (qTurbine * pWater);
timeFill = mass / (qPump * pWater);

energy_In = mass*(gravity*(botElev + resDepth/2) + (pipeFric*pipeLen*...
velocityU^2 / (2*pipeDiam)) + (bendCo1 * velocityU^2 / 2)) / np;

resArea = qPump * timeFill / resDepth;
sysEffic = energy_Out / energy_In;

%% Output
 
fprintf('\nThe reservoir surface area is %.2E m^2.\n', resArea);
fprintf('The time to fill the reservoir is %.2f hours.', timeFill / 3600);
fprintf('\nThe time to empty the reservoir is ')
fprintf('%.2f hours.\n', timeEmpty / 3600);
fprintf('The input Energy is %.2f MWh.\n', energy_In * 2.7777 * 10 ^ -10);
fprintf('The system efficiency is %.2f.\n', sysEffic);
 
 
