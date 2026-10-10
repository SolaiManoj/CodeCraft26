#include <stdio.h>
#include <string.h>
struct Request {
    char id[10];
    char location[30];
    int people;
    char emergency[20];
    char resources[30];
    char team[30];      
    char status[20];   
};
struct Request list[10]; 
int total_requests = 0;

int main()
{
    int choice;
    char search_id[10];
    int found;
    int critical_count, normal_count, completed_count, pending_count;
    while(1)
    {
        printf("Enter choice (1-7): ");
        scanf("%d", &choice);
        if (choice == 1) 
        {
            if (total_requests >= 10) {
                printf("System full! Cannot add more requests.\n");
            } 
            else {
                printf("\n  REGISTRATION: \n");
                printf("Request ID: ");
                scanf("%9s", list[total_requests].id);
                printf("Location: ");
                scanf("%29s", list[total_requests].location);
                printf("People: ");
                scanf("%d", &list[total_requests].people);
                printf("Emergency Level:");
                scanf("%19s", list[total_requests].emergency);
                printf("Resources: ");
                scanf("%29s", list[total_requests].resources);
                strcpy(list[total_requests].team, "None");
                strcpy(list[total_requests].status, "Pending");
                printf("Successfully Registered!\n");
                total_requests++;
            }
        } 
        else if (choice == 2) 
        {
            if (total_requests == 0) {
                printf("No requests found.\n");
            } 
            else {
                printf("\n--- CURRENT REQUESTS ---\n");
                for (int i = 0; i < total_requests; i++) {
                    if (strcmp(list[i].emergency, "Critical") == 0) {
                        printf("[%s] Loc: %s -People: %d -Level: %s -Team: %s -Status: %s\n", 
                               list[i].id, list[i].location, list[i].people, 
                               list[i].emergency, list[i].team, list[i].status);
                    }
                }
                for (int i = 0; i < total_requests; i++) {
                    if (strcmp(list[i].emergency, "Critical") != 0) {
                        printf("[%s] Loc: %s -People: %d Level: %s | Team: %s | Status: %s\n", 
                               list[i].id, list[i].location, list[i].people, 
                               list[i].emergency, list[i].team, list[i].status);
                    }
                }
            }
        } 
        else if (choice == 3) 
        {
            printf("Enter Request ID to assign team: ");
            scanf("%9s", search_id);
            found = 0;
            for (int i = 0; i < total_requests; i++) {
                if (strcmp(list[i].id, search_id) == 0) {
                    printf("Enter Rescue Team Name: ");
                    scanf("%29s", list[i].team);
                    printf("Team Assigned!\n");
                    found = 1;
                    break;
                }
            }
            if (found == 0)
             printf("Request ID not found.\n");
        } 
        else if (choice == 4) 
        {
            printf("Enter Request ID to update status: ");
            scanf("%9s", search_id);
            found = 0;
            for (int i = 0; i < total_requests; i++) {
                if (strcmp(list[i].id, search_id) == 0) {
                    printf("Enter New Status (Pending/Completed): ");
                    scanf("%19s", list[i].status);
                    printf("Status Updated!\n");
                    found = 1;
                    break;
                }
            }
            if (found == 0) 
            printf("Request ID not found.\n");
        } 
        else if (choice == 5) 
        {
            printf("Enter Request ID to search: ");
            scanf("%9s", search_id);
            found = 0;
            for (int i = 0; i < total_requests; i++) {
                if (strcmp(list[i].id, search_id) == 0) {
                    printf("\n--- DETAILS FOUND ---\n");
                    printf("ID: %s\nLocation: %s\nPeople: %d\nLevel: %s\nResources: %s\nTeam: %s\nStatus: %s\n", 
                           list[i].id, list[i].location, list[i].people, 
                           list[i].emergency, list[i].resources, list[i].team, list[i].status);
                    found = 1;
                    break;
                }
            }
            if (found == 0) 
            printf("Request ID not found.\n");
        }
        else if (choice == 6) 
        {
            critical_count = 0; normal_count = 0; completed_count = 0; pending_count = 0;
            
            for (int i = 0; i < total_requests; i++) {
                if (strcmp(list[i].emergency, "Critical") == 0) critical_count++;
                else normal_count++;
                
                if (strcmp(list[i].status, "Completed") == 0) completed_count++;
                else pending_count++;
            }
            printf("SUMMARY \n");
            printf("Total Requests: %d\n", total_requests);
            printf("Critical Cases: %d\n", critical_count);
            printf("Normal Cases:   %d\n", normal_count);
            printf("Completed:      %d\n", completed_count);
            printf("Pending:        %d\n", pending_count);
        }
        else if (choice == 7) 
        {
            printf("Exiting Program...\n");
            break;
        } 
        else 
        {
            printf("Invalid selection! Use options 1 to 7.\n");
        }
    }
}
