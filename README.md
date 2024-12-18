C++ program simulates a patient queue system in a healthcare setting, 
tracking the arrival and processing of patients by nurses specializing in wound care, 
adult patients, and children.

Patient Management:

Patients are represented with their speciality (wound, adult, or children) and processing time.
Patient data is read from c:\data\dataclient.txt.

Queue Simulation:

Three separate queues for wound, adult, and children specialities.
Patients are processed in order of arrival by nurses with variable availability.
Time Simulation:

Simulates patient flow over a user-defined time period.
Tracks the number of patients in each queue at each time step.

Output:

Displays results in a tabular format.
Each row shows the time step, and columns display queue sizes and patient processing times.

Requirements
A valid input file located at c:\data\dataclient.txt.
