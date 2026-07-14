#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient
{
    int id;
    char name[50];
    int age;
    char gender[10];
    char disease[50];
    char doctor[50];
    long long mobile;
};

void menu();
void addPatient();
void viewPatients();
void searchPatient();
void updatePatient();
void deletePatient();
void generateBill();
void menu();

int main()

{
    int choice;

    while (1)
    {
        menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addPatient();
            break;

        case 2:

            viewPatients();
            break;

        case 3:
            searchPatient();
            break;

        case 4:
            updatePatient();
            break;

        case 5:
            deletePatient();
            break;

        case 6:
            generateBill();
            break;

        case 7:
            printf("\nThank You!\n");
            exit(0);

        default:
            printf("\nInvalid Choice!\n");
        }
    }
}

void menu()
{
    printf("\n====================================");
    printf("\n   HOSPITAL MANAGEMENT SYSTEM");
    printf("\n====================================");
    printf("\n1. Add Patient");
    printf("\n2. View Patients");
    printf("\n3. Search Patient");
    printf("\n4. Update Patient");
    printf("\n5. Delete Patient");
    printf("\n6. Generate Bill");
    printf("\n7. Exit");
    printf("\n\nEnter Choice : ");
}

void addPatient()
{
    FILE *fp;
    struct Patient p;

    fp = fopen("patients.dat", "ab");

    if (fp == NULL)
    {
        printf("\nFile Error!");
        return;
    }

    printf("\nEnter Patient ID : ");
    scanf("%d", &p.id);

    printf("Enter Name : ");
    scanf(" %[^\n]", p.name);

    printf("Enter Age : ");
    scanf("%d", &p.age);

    printf("Enter Gender : ");
    scanf("%s", p.gender);

    printf("Enter Disease : ");
    scanf(" %[^\n]", p.disease);

    printf("Enter Doctor Name : ");
    scanf(" %[^\n]", p.doctor);

    printf("Enter Mobile Number : ");
    scanf("%lld", &p.mobile);

    fwrite(&p, sizeof(p), 1, fp);

    fclose(fp);

    printf("\nPatient Added Successfully!\n");
}

void viewPatients()
{
    FILE *fp;
    struct Patient p;

    fp = fopen("patients.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\n========== Patient List ==========\n");

    while (fread(&p, sizeof(struct Patient), 1, fp))
    {
        printf("\nPatient ID : %d", p.id);
        printf("\nName       : %s", p.name);
        printf("\nAge        : %d", p.age);
        printf("\nGender     : %s", p.gender);
        printf("\nDisease    : %s", p.disease);
        printf("\nDoctor     : %s", p.doctor);
        printf("\nMobile     : %lld", p.mobile);
        printf("\n-----------------------------");
    }

    fclose(fp);
}

void searchPatient()
{
    FILE *fp;
    struct Patient p;
    int id, found = 0;

    fp = fopen("patients.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\nEnter Patient ID to Search : ");
    scanf("%d", &id);

    while (fread(&p, sizeof(struct Patient), 1, fp))
    {
        if (p.id == id)
        {
            printf("\n========== PATIENT DETAILS ==========\n");
            printf("Patient ID : %d\n", p.id);
            printf("Name       : %s\n", p.name);
            printf("Age        : %d\n", p.age);
            printf("Gender     : %s\n", p.gender);
            printf("Disease    : %s\n", p.disease);
            printf("Doctor     : %s\n", p.doctor);
            printf("Mobile     : %lld\n", p.mobile);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nPatient Not Found!\n");
    }

    fclose(fp);
}

void updatePatient()
{
    FILE *fp;
    struct Patient p;
    int id, found = 0;

    fp = fopen("patients.dat", "rb+");

    if (fp == NULL)
    {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\nEnter Patient ID to Update : ");
    scanf("%d", &id);

    while (fread(&p, sizeof(struct Patient), 1, fp))
    {
        if (p.id == id)
        {
            found = 1;

            printf("\nPatient Found!");
            printf("\nEnter New Name : ");
            scanf(" %[^\n]", p.name);

            printf("Enter New Age : ");
            scanf("%d", &p.age);

            printf("Enter New Gender : ");
            scanf("%s", p.gender);

            printf("Enter New Disease : ");
            scanf(" %[^\n]", p.disease);

            printf("Enter New Doctor Name : ");
            scanf(" %[^\n]", p.doctor);

            printf("Enter New Mobile Number : ");
            scanf("%lld", &p.mobile);

            fseek(fp, -sizeof(struct Patient), SEEK_CUR);
            fwrite(&p, sizeof(struct Patient), 1, fp);

            printf("\nPatient Updated Successfully!\n");
            break;
        }
    }

    if (found == 0)
    {
        printf("\nPatient Not Found!\n");
    }

    fclose(fp);
}

void deletePatient()
{
    FILE *fp, *temp;
    struct Patient p;
    int id, found = 0;

    fp = fopen("patients.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo Records Found!\n");
        return;
    }

    temp = fopen("temp.dat", "wb");

    printf("\nEnter Patient ID to Delete : ");
    scanf("%d", &id);

    while (fread(&p, sizeof(struct Patient), 1, fp))
    {
        if (p.id == id)
        {
            found = 1;
            printf("\nPatient Deleted Successfully!\n");
        }
        else
        {
            fwrite(&p, sizeof(struct Patient), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("patients.dat");
    rename("temp.dat", "patients.dat");

    if (found == 0)
    {
        printf("\nPatient Not Found!\n");
    }
}

void generateBill()
{
    FILE *fp;
    struct Patient p;
    int id, found = 0;
    float doctorFee, medicineCharge, roomCharge, testCharge, total;

    fp = fopen("patients.dat", "rb");

    if(fp == NULL)
    {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\nEnter Patient ID : ");
    scanf("%d", &id);

    while(fread(&p, sizeof(struct Patient), 1, fp))
    {
        if(p.id == id)
        {
            found = 1;

            printf("\nEnter Doctor Fee : ");
            scanf("%f", &doctorFee);

            printf("Enter Medicine Charge : ");
            scanf("%f", &medicineCharge);

            printf("Enter Room Charge : ");
            scanf("%f", &roomCharge);

            printf("Enter Test Charge : ");
            scanf("%f", &testCharge);

            total = doctorFee + medicineCharge + roomCharge + testCharge;

            printf("\n======================================");
            printf("\n          HOSPITAL BILL");
            printf("\n======================================");
            printf("\nPatient ID      : %d", p.id);
            printf("\nPatient Name    : %s", p.name);
            printf("\nDoctor          : %s", p.doctor);
            printf("\nDisease         : %s", p.disease);
            printf("\n--------------------------------------");
            printf("\nDoctor Fee      : %.2f", doctorFee);
            printf("\nMedicine Charge : %.2f", medicineCharge);
            printf("\nRoom Charge     : %.2f", roomCharge);
            printf("\nTest Charge     : %.2f", testCharge);
            printf("\n--------------------------------------");
            printf("\nTotal Bill      : %.2f", total);
            printf("\n======================================\n");

            break;
        }
    }

    if(found == 0)
    {
        printf("\nPatient Not Found!\n");
    }

    fclose(fp);
}