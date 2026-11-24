#include <stdio.h>
#include <string.h>

// Structure to store appointment details
struct Appointment
{
    int id;
    char patientName[50];
    char doctorName[50];
    char date[20];
    char time[20];
};

// Global variables
struct Appointment appointments[100];
int count = 0;

// Function to add an appointment
void addAppointment()
{
    if (count >= 100)
    {
        printf("\nAppointment list is full!");
        return;
    }

    appointments[count].id = count + 1;

    printf("\nEnter Patient Name: ");
    scanf(" %[^\n]", appointments[count].patientName);

    printf("Enter Doctor Name: ");
    scanf(" %[^\n]", appointments[count].doctorName);

    printf("Enter Date: ");
    scanf(" %[^\n]", appointments[count].date);

    printf("Enter Time: ");
    scanf(" %[^\n]", appointments[count].time);

    count++;

    printf("\nAppointment added successfully!\n");
}

// Function to view all appointments
void viewAppointments()
{
    int i;

    if (count == 0)
    {
        printf("\nNo appointments available!\n");
        return;
    }

    printf("\n--- Appointment Details ---\n");

    for (i = 0; i < count; i++)
    {
        printf("\nAppointment ID: %d", appointments[i].id);
        printf("\nPatient Name: %s", appointments[i].patientName);
        printf("\nDoctor Name: %s", appointments[i].doctorName);
        printf("\nDate: %s", appointments[i].date);
        printf("\nTime: %s\n", appointments[i].time);
    }
}

// Function to search an appointment
void searchAppointment()
{
    int id;
    int i;
    int found = 0;

    printf("\nEnter Appointment ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (appointments[i].id == id)
        {
            printf("\nAppointment Found!");
            printf("\nPatient Name: %s", appointments[i].patientName);
            printf("\nDoctor Name: %s", appointments[i].doctorName);
            printf("\nDate: %s", appointments[i].date);
            printf("\nTime: %s\n", appointments[i].time);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nAppointment not found!\n");
    }
}

// Main function
int main()
{
    int choice;

    // Display menu repeatedly
    do
    {
        printf("\n===== DOCTOR APPOINTMENT SCHEDULER =====");
        printf("\n1. Add Appointment");
        printf("\n2. View Appointments");
        printf("\n3. Search Appointment");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Perform operation based on user choice
        switch (choice)
        {
            case 1:
                addAppointment();
                break;

            case 2:
                viewAppointments();
                break;

            case 3:
                searchAppointment();
                break;

            case 4:
                printf("\nThank you for using the program!");
                break;

            default:
                printf("\nInvalid choice! Please try again.");
        }

    } while (choice != 4);

    return 0;
}
