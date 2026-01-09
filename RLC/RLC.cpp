// RLC.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <cmath>

// global variables
double planetMass;
double planetRadius;
double orbitRadius;
const double GRAVITY = 0.00000000006674;


// functions
void escapeVelocity() 
{
    std::cout << "\n\n\n--- ESCAPE VELOCITY CALCULATOR ---\n";
    std::cout << "Enter Planet's Mass (in kg): ";
    std::cin >> planetMass;
    std::cout << "Enter Planet's Radius (in meters): ";
    std::cin >> planetRadius;
    
    std::cout << "\nEscape Velocity: " << sqrt(2 * GRAVITY * (planetMass / planetRadius)) << " m/s." << std::endl;
}

void orbitalVelocity()
// Orbital velocity is the speed needed to orbit a planet (stay in space around it, not escape it).
{
    std::cout << "\n\n\n--- ORBITAL VELOCITY CALCULATOR ---\n";
    std::cout << "Enter Planet's Mass (in kg): ";
    std::cin >> planetMass;
    std::cout << "Enter Orbit's Radius (in meters): ";
    std::cin >> orbitRadius;

    std::cout << "\nOrbital Velocity: " << sqrt((GRAVITY * planetMass) / orbitRadius) << " m/s." << std::endl;
}

void rocketEquation()
{
    std::cout << "Rocket Equation Coming Soon..";
}

void fuelRequirements()
{
    std::cout << "Fuel Requirements Coming Soon..";
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

