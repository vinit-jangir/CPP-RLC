// RLC.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <cmath>

// global variables
double planetMass;
double planetRadius;
double orbitRadius;
double exhaustVelocity;
double finalMass;
const double GRAVITY = 0.00000000006674;


// functions
void escapeVelocity() 
{
    std::cout << "\n\n--- ESCAPE VELOCITY CALCULATOR ---\n";
    std::cout << "Enter Planet's Mass (in kg): ";
    std::cin >> planetMass;
    std::cout << "Enter Planet's Radius (in meters): ";
    std::cin >> planetRadius;
    
    std::cout << "\nEscape Velocity: " << sqrt(2 * GRAVITY * (planetMass / planetRadius)) << " m/s." << std::endl;
}

void orbitalVelocity()
// Orbital velocity is the speed needed to orbit a planet (stay in space around it, not escape it).
{
    std::cout << "\n\n--- ORBITAL VELOCITY CALCULATOR ---\n";
    std::cout << "Enter Planet's Mass (in kg): ";
    std::cin >> planetMass;
    std::cout << "Enter Orbit's Radius (in meters): ";
    std::cin >> orbitRadius;

    std::cout << "\nOrbital Velocity: " << sqrt((GRAVITY * planetMass) / orbitRadius) << " m/s." << std::endl;
}

void rocketEquation()
// This uses the Tsiolkovsky Rocket Equation: Δv = ve * ln(m0/mf)
{
    double initialMass;
   
    std::cout << "\n\n--- ROCKET EQUATION CALCULATOR ---\n";

    std::cout << "Enter the exhaust velocity (m/s): ";
    std::cin >> exhaustVelocity;
    std::cout << "Enter initial mass (including fuel) (in kg): ";
    std::cin >> initialMass;
    std::cout << "Enter final mass (empty rocket) (in kg): ";
    std::cin >> finalMass;

    std::cout << "\nCalculating...\n";

    double delta_V = exhaustVelocity * log(initialMass / finalMass);
    double massRatio = initialMass / finalMass;
    double fuelConsumed = initialMass - finalMass;
    double fuelPercentage = (fuelConsumed / initialMass) * 100;

    std::cout << "\n\nRESULTS:\n";
    std::cout << "========\n";
    std::cout << "Delta-V acheived: " << delta_V << std::endl;
    std::cout << "Mass ratio: " << massRatio << std::endl;
    std::cout << "Fuel consumed: " << fuelConsumed << std::endl;
    std::cout << "Fuel percentage: " << fuelConsumed << std::endl;


    std::cout << "\nAnalysis:";
    if (delta_V >= 9400)
    {
        std::cout << "\nSufficient propellant for Low Earth orbit!";
    }
    else 
    {
        std::cout << "\nPropellant  is not succificent for Low Earth orbit; " << 9400 - delta_V << " more propellant is required." << std::endl;
    }
}

void fuelRequirements()
// Calculate how much fuel you need for a desired Delta-V
{
    double desiredDelta_V;

    std::cout << "\n\n--- FUEL REQUIREMENTS ---\n";

    std::cout << "Enter desired Delta-V (m/s): ";
    std::cin >> desiredDelta_V;
    std::cout << "Enter the exhaust velocity (m/s): ";
    std::cin >> exhaustVelocity;
    std::cout << "Enter final mass (empty rocket) (in kg): ";
    std::cin >> finalMass;

    double massRatio = exp(desiredDelta_V / exhaustVelocity);
    double initialMass = finalMass * massRatio;
    double fuelNeeded = initialMass - finalMass;
    double fuel_percentage = ((initialMass - finalMass) * 100) / initialMass;

    std::cout << "\n\nRESULTS:\n";
    std::cout << "========\n";
    std::cout << "Fuel needed: " << fuelNeeded << std::endl;
    std::cout << "Initial mass (including fuel): " << initialMass << std::endl;
    std::cout << "Mass ratio: " << massRatio << std::endl;
    std::cout << "Fuel percentage: " << fuel_percentage << std::endl;

    std::cout << "\nAnalysis:";
    if (fuel_percentage > 90)
    {
        std::cout << "\nWarning! Very high fuel ratio - may not be practical!";
    }
    else if (fuel_percentage < 50)
    {
        std::cout << "\nEfficient fuel usage!";
    }
    else
    {
        std::cout << "\nReasonable fuel requirements" << std::endl;
    }
}

void launchTrajectory()
{
    std::cout << "Launch Trajectory Coming Soon..";
}

void compareRockets()
{
    std::cout << "Compare Rockets Coming Soon..";
}

int main()
{
    std::cout << "=====================================\n";
    std::cout << "       ROCKET LAUNCH CALCULATOR      \n";
    std::cout << "=====================================\n\n";
    std::cout << "MAIN MENU:\n";
    std::cout << "1. Calculate Escape Velocity\n";
    std::cout << "2. Calculate Orbital Velocity\n";
    std::cout << "3. Rocket Equation (Delta-V Calculator)\n";
    std::cout << "4. Calculate Fuel Requirements\n";
    std::cout << "5. Launch Trajectory Simulator\n";
    std::cout << "6. Compare Real Rockets\n";
    std::cout << "7. Exit\n";
    
    int choice;
    std::cout << "\nEnter your choice: ";
    std::cin >> choice;


    switch (choice)
    {
        case 1: escapeVelocity();   break;
        case 2: orbitalVelocity();  break;
        case 3: rocketEquation();   break;
        case 4: fuelRequirements(); break;
        case 5: launchTrajectory(); break;
        case 6: compareRockets();   break;
        case 7: std::cout << "\nExiting program...";    break;
        default: std::cout << "\nPlease Choose the appropriate choice..";
    }  

    return 0;
}

