// RLC.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <cmath>
#include <string>

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
// Simulating a rocket launch with real-time altitude tracking
{
    double thrust;                  // force pushing the rocket
    double rocketMass;
    double dragCoefficient;         // air resistance
    double timeStep = 1.0;          // simulate 1 second at a time
    double altitude = 0.0;          // starting on ground
    double velocity = 0.0;          // starting from rest
    int timeElapsed = 0;            // in seconds

    
    std::cout << "\n\n--- LAUNCH TRAJECTORY SIMULATOR ---\n";

    std::cout << "Enter thrust force (Newrons): ";
    std::cin >> thrust;
    std::cout << "Enter rocket mass (kg): ";
    std::cin >> rocketMass;
    std::cout << "Enter drag coefficient (0.1 - 0.5): ";
    std::cin >> dragCoefficient;
    std::cout << "How many secods to simulate? ";
    std::cin >> timeElapsed;

    std::cout << "\nLaunching...\n\n";

    for (int time = 0; time <= timeElapsed; time++)
    {
        double acceleration = (thrust - (rocketMass * 9.81) - (dragCoefficient * velocity * velocity)) / rocketMass;
        velocity = velocity + (acceleration * timeStep);

        if (velocity < 0) velocity = 0;

        altitude = altitude + (velocity * timeStep);

        if (altitude < 0) altitude = 0;

        if (time % 10 == 0 || time == 0)
        {
            std::cout << "T+" << time << "s: Altitude: " << altitude << " m | velocity: " << velocity << " m/s" << std::endl;
        }
    }

    std::cout << "\n\nFINAL RESULTS\n";
    std::cout << "================\n";
    std::cout << "\nFinal altitude (in meters): " << altitude << std::endl;
    std::cout << "\nFinal altitude (in kms): " << altitude / 1000 << std::endl;
    std::cout << "\nFinal velocity (in m/s): " << velocity << std::endl;
    std::cout << "\nTotal time (in seconds): " << timeElapsed << std::endl;

    std::cout << "\nMilestone:";
    if (altitude > 100000)
    {
        std::cout << "\nMilestone Reached..";
    }
    else if (altitude > 10000)
    {
        std::cout << "\nMilestone was in stratosphere!";
    }
    else
    {
        std::cout << "\nMilestone failed" << std::endl;
    }
}

void compareRockets()
{
    int rocketOne, rocketTwo;
    
    std::string rocketNames[5]{ "Saturn V(Apollo Program)" , "Falcon 9 (SpaceX)" , "Starship (SpaceX)" , "Space Shuttle","Soyuz" };
    double heights[5] = { 110.6 , 70 , 120, 56.1, 46.3 };                                                                               // in meters
    double masses[5] = { 2970000 , 549054, 5000000 , 2030000 , 308000 };                                                                // in kgs
    double payloads[5] = { 140000 , 22800, 100000, 27500, 7020 };                                                                       // payload to Lower-Earth-Orbit in kgs
    double thrusts[5] = {35100, 7607, 72000, 30160, 4145};                                                                              // in KiloNewton
    std::string fuelTypes[5] = { "RP-1/LOX" , "RP-1/LOX" , "CH4/LOX" , "H2/LOX+Solid" , "RP-1/LOX" };
    std::string reusable[5] = { "No", "Yes", "Yes", "Partially", "No"};                                                                 // Boolean Yes/No
    double deltaVs[5] = { 9400 , 9500 , 9000 , 9200 , 9300 };                                                                          // in m/s

    
    std::cout << "\n\n--- REAL ROCKET DATABASE ---\n";
    std::cout << "\nAvailable Rockets:";

    for (int list = 0; list <= 4; list++)
    {
        std::cout << "\n" << (list + 1) << "." << rocketNames[list];
    }

    std::cout << "\n\nEnter first rocket: ";
    std::cin >> rocketOne;
    std::cout << "Enter second rocket: ";
    std::cin >> rocketTwo;

    if ((rocketOne > 0 && rocketOne < 5) && (rocketTwo > 0 && rocketTwo < 5))
    {
        std::cout << "\n\nCOMPARISON:" << std::endl;
        std::cout << "\n\===========" << std::endl;

        std::cout << rocketNames[rocketOne] << "\n";
        std::cout << "Height:             " << heights[rocketOne] << " m\n";
        std::cout << "Mass:               " << masses[rocketOne] << " kg\n";
        std::cout << "Payload to LEO:     " << payloads[rocketOne] << " kg\n";
        std::cout << "Thrust:             " << thrusts[rocketOne] << " kN\n";
        std::cout << "Fuel Type:          " << fuelTypes[rocketOne] << "\n"; 
        std::cout << "Reusable:           " << reusable[rocketOne] << "\n"; 
        std::cout << "Delta-V:            ~" << deltaVs[rocketOne] << " m/s\n\n"; 

        std::cout << rocketNames[rocketTwo] << "\n";
        std::cout << "Height:             " << heights[rocketTwo] << " m\n";
        std::cout << "Mass:               " << masses[rocketTwo] << " kg\n";
        std::cout << "Payload to LEO:     " << payloads[rocketTwo] << " kg\n";
        std::cout << "Thrust:             " << thrusts[rocketTwo] << " kN\n";
        std::cout << "Fuel Type:          " << fuelTypes[rocketTwo] << "\n";
        std::cout << "Reusable:           " << reusable[rocketTwo] << "\n";
        std::cout << "Delta-V:            ~" << deltaVs[rocketTwo] << " m/s\n";

        std::cout << "\nPress Enter to continue...";
        std::cin.ignore();
        std::cin.get();
    }
    else
    {
        std::cout << "\n\nInvalid selection, please select from the list.\n\n";
    }
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

