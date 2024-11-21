#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int totalReminders = 0; 
void stopReminders(int sig) {
    printf("\nTotal reminders sent: %d\n", totalReminders);
    exit(0); 
}

void sendReminder() {
    while (totalReminders < 10) { 
        printf("Reminder: Time to check your task!\n");
        totalReminders++; 
        sleep(10); 
    }
    printf("\nReached 10 reminders, stopping now.\n");
}

int main() {
    signal(SIGINT, stopReminders); 

    printf("Welcome to the reminder system!\n");
    printf("Press Ctrl+C to stop the reminders at any time.\n");

    sendReminder(); 

    printf("Program has finished sending reminders.\n");
    return 0;
}