#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOLD "\033[1m"
#define RESET "\033[0m"

struct transactionTime
{
    int transactionDay;
    int transactionMonth;
    int transactionYear;
};

struct priceUnit
{
    int quantity;
    double pricePerUnit;
    double totalPrice;
};

struct dataSales
{
    char customerName[101];
    char carType[21];
    char carBrand[51];
    char carName[101];
    int carYear;
    char fuelType[21];
    int engineDisplacement;
    char transmissionType[51];
    struct priceUnit price;
    struct transactionTime time;
};

void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void capital(char *str)
{
    int firstChar = 1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            firstChar = 1;
        }
        else
        {
            if (firstChar == 1)
            {
                str[i] = toupper(str[i]);
                firstChar = 0;
            }
        }
    }
}

void allcapital(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]);
    }
}

void displayIntroduction()
{
    printf(BOLD "\tFinal Project LAB Car & Vehicle" RESET "\n");
    printf(BOLD "==============================================" RESET "\n");
    printf(BOLD " Nama:" RESET " Nico Pranama Hadi        (2702344204)\n");
    printf(BOLD " Nama:" RESET " Muhammad Abyan Nandhiko  (2702344204)\n");
    printf(BOLD " Nama:" RESET " Leonel Marcelino Agustav (2702344204)\n");
    printf(BOLD "==============================================" RESET "\n");
    clearBuffer();
    system("cls");
}

void entryData()
{
    FILE *sales = fopen("sales.txt", "a+");
    struct dataSales data;

    if (sales == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    char answer;

    do
    {
        do
        {
            printf(BOLD "Input Transaction Date (DD/MM/YY): " RESET);
            int result =
                scanf("%d %d %d", &data.time.transactionDay,
                      &data.time.transactionMonth, &data.time.transactionYear);

            if (result != 3)
            {
                printf("Invalid input. Please enter a valid date in the format.\n");
                system("cls");
                continue;
            }
            else if (data.time.transactionDay < 1 ||
                     data.time.transactionDay > 31)
            {
                printf("Invalid date. Please enter a valid date within the specified "
                       "range.\n");
                system("cls");
                continue;
            }
            else if (data.time.transactionMonth < 1 ||
                     data.time.transactionMonth > 12)
            {
                printf("Invalid month. Please enter a valid month.\n");
                system("cls");
                continue;
            }
            else if (data.time.transactionYear < 1960 ||
                     data.time.transactionYear > 2100)
            {
                printf("Invalid year. Please enter a valid year.\n");
                system("cls");
                continue;
            }
            else
            {
                break;
            }
        } while (1);

        system("cls");

        printf(BOLD "Input Customer Name: " RESET);
        scanf(" %[^\n]", data.customerName);
        capital(data.customerName);
        system("cls");

        printf(BOLD "Input Car Type: " RESET "\n");
        printf("1. Hatchback\n");
        printf("2. MPV\n");
        printf("3. SUV\n");
        printf("4. Sedan\n");
        printf("5. Wagon\n");
        printf("6. Coupe\n");
        printf("7. Van\n");
        printf("8. Truck\n");
        printf("9. Electric\n");
        printf("10. Crossover\n");
        printf("Product type: ");
        scanf(" %[^\n]", data.carType);

        if (strcmp(data.carType, "mpv") == 0 || strcmp(data.carType, "suv") == 0)
        {
            allcapital(data.carType);
        }
        else
        {
            capital(data.carType);
        }
        system("cls");

        printf(BOLD "Input Car Brand:" RESET "\n");
        printf("1. Honda\n");
        printf("2. Toyota\n");
        printf("3. Suzuki\n");
        printf("4. Nissan\n");
        printf("5. Mitsubishi\n");
        printf("6. Daihatsu\n");
        printf("7. Chevrolet\n");
        printf("8. Hyundai\n");
        printf("9. Wuling\n");
        printf("Car Brand: ");
        scanf(" %[^\n]", data.carBrand);
        capital(data.carBrand);
        system("cls");

        printf(BOLD "Input Car Year: " RESET);
        scanf(" %d", &data.carYear);
        system("cls");

        printf(BOLD "Input Car Name: " RESET);
        scanf(" %[^\n]", data.carName);
        capital(data.carName);
        system("cls");

        printf(BOLD "Input Fuel Type:" RESET "\n");
        printf("1. Gasoline\n");
        printf("2. Diesel\n");
        printf("3. Hybrid\n");
        printf("4. Electric\n");
        printf("Fuel Type: ");
        scanf(" %[^\n]", data.fuelType);
        capital(data.fuelType);
        system("cls");

        printf(BOLD "Input Engine Displacement (cc): " RESET);
        scanf(" %d", &data.engineDisplacement);
        system("cls");

        printf(BOLD "Input Transmission Type:" RESET "\n");
        printf("1. Manual\n");
        printf("2. Automated Manual\n");
        printf("3. DCT\n");
        printf("4. CVT\n");
        printf("Transmission Type: ");
        scanf(" %[^\n]", data.transmissionType);

        if (strcmp(data.transmissionType, "manual") == 0 ||
            strcmp(data.transmissionType, "automated manual") == 0)
        {
            capital(data.transmissionType);
        }
        else if (strcmp(data.transmissionType, "dct") == 0 ||
                 strcmp(data.transmissionType, "cvt") == 0)
        {
            allcapital(data.transmissionType);
        }
        system("cls");

        double totalPrice = 0;
        double pricePerUnit = 0;

        printf(BOLD "Input Quantity: " RESET);
        scanf(" %d", &data.price.quantity);
        system("cls");

        printf(BOLD "Input Price per Unit: " RESET);
        scanf(" %lf", &data.price.pricePerUnit);
        system("cls");

        data.price.totalPrice = data.price.pricePerUnit * data.price.quantity;

        printf(BOLD "Total Price: %.0lf", data.price.totalPrice);
        system("cls");

        fprintf(sales, "%02d%02d%04d,%s,%s,%s,%d,%s,%s,%d,%s,%d,%.0lf,%.0lf\n",
                data.time.transactionDay, data.time.transactionMonth,
                data.time.transactionYear, data.customerName, data.carType,
                data.carBrand, data.carYear, data.carName, data.fuelType,
                data.engineDisplacement, data.transmissionType, data.price.quantity,
                data.price.pricePerUnit, data.price.totalPrice);

        printf("Do you want to input another data? (y/n): ");
        scanf(" %c", &answer);

        clearBuffer();

    } while (answer == 'y' || answer == 'Y');

    fclose(sales);
}

int compareDates(int day1, int month1, int year1, int day2, int month2, int year2)
{
    if (year1 < year2)
        return -1;
    if (year1 > year2)
        return 1;
    if (month1 < month2)
        return -1;
    if (month1 > month2)
        return 1;
    if (day1 < day2)
        return -1;
    if (day1 > day2)
        return 1;
    return 0;
}

void alldata()
{
    struct dataSales data;

    FILE *sales = fopen("sales.txt", "r");
    if (sales == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    printf("===================================================================================================================================================\n");
    printf("                                                             All Sales Data                                                                       \n");
    printf("===================================================================================================================================================\n");
    printf("| %s | %s | %-10s | %-7s | %s | %-5s | %-8s | %-8s | %s | %s | %-9s | %s |\n",
           "Transaction Date", "Customer", "Car Type", "Brand", "Car Name", "Year", "Fuel", "CC", "Transmission", "Quantity", "Price", "Total Price");
    printf("===================================================================================================================================================\n");

    while (fscanf(sales, "%2d%2d%4d,%100[^,],%15[^,],%15[^,],%d,%100[^,],%25[^,],%d,%15[^,],%d,%lf,%lf\n",
                  &data.time.transactionDay, &data.time.transactionMonth, &data.time.transactionYear,
                  data.customerName, data.carType, data.carBrand, &data.carYear, data.carName, data.fuelType, &data.engineDisplacement,
                  data.transmissionType, &data.price.quantity, &data.price.pricePerUnit, &data.price.totalPrice) != EOF)
    {
        printf("| %02d/%02d/%-10.04d | %-8s | %-10s | %-7s | %-8s | %-5d | %-8s | %-8d | %-12s | %-8d | %-7.0lf | %-12.0lf|\n",
               data.time.transactionDay, data.time.transactionMonth, data.time.transactionYear, data.customerName, data.carType,
               data.carBrand, data.carName, data.carYear, data.fuelType, data.engineDisplacement,
               data.transmissionType, data.price.quantity, data.price.pricePerUnit, data.price.totalPrice);
    }

    printf("===================================================================================================================================================\n");
    fclose(sales);
}

void daterange()
{
    struct dataSales data;

    int startDay, startMonth, startYear;
    int endDay, endMonth, endYear;

    FILE *sales = fopen("sales.txt", "r");
    if (sales == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    printf("Input start date (DD MM YYYY): ");
    scanf("%d %d %d", &startDay, &startMonth, &startYear);

    printf("Input end date (DD MM YYYY): ");
    scanf("%d %d %d", &endDay, &endMonth, &endYear);

    printf("===================================================================================================================================================\n");
    printf("                                                    Sales Data within the Date Range                                                              \n");
    printf("===================================================================================================================================================\n");
    printf("| %s | %s | %-10s | %-7s | %s | %-5s | %-8s | %-8s | %s | %s | %-9s | %s |\n",
           "Transaction Date", "Customer", "Car Type", "Brand", "Car Name", "Year", "Fuel", "CC", "Transmission", "Quantity", "Price", "Total Price");
    printf("===================================================================================================================================================\n");

    while (fscanf(sales, "%2d%2d%4d,%100[^,],%15[^,],%15[^,],%d,%100[^,],%25[^,],%d,%15[^,],%d,%lf,%lf\n",
                  &data.time.transactionDay, &data.time.transactionMonth, &data.time.transactionYear,
                  data.customerName, data.carType, data.carBrand, &data.carYear, data.carName, data.fuelType, &data.engineDisplacement,
                  data.transmissionType, &data.price.quantity, &data.price.pricePerUnit, &data.price.totalPrice) != EOF)
    {
        if (compareDates(data.time.transactionDay, data.time.transactionMonth, data.time.transactionYear, startDay, startMonth, startYear) >= 0 &&
            compareDates(data.time.transactionDay, data.time.transactionMonth, data.time.transactionYear, endDay, endMonth, endYear) <= 0)
        {
            printf("| %02d/%02d/%-10.04d | %-8s | %-10s | %-7s | %-8s | %-5d | %-8s | %-8d | %-12s | %-8d | %-7.0lf | %-12.0lf|\n",
                   data.time.transactionDay, data.time.transactionMonth, data.time.transactionYear,
                   data.customerName, data.carType, data.carBrand, data.carName,
                   data.carYear, data.fuelType, data.engineDisplacement,
                   data.transmissionType, data.price.quantity, data.price.pricePerUnit, data.price.totalPrice);
        }
    }

    printf("===================================================================================================================================================\n");
    fclose(sales);
}

void displayData()
{
    struct dataSales data;

    int choice;

    printf(BOLD "========== Display Data ==========" RESET "\n");
    printf("1. Display All Data\n");
    printf("2. Display by Date Range\n");
    printf(BOLD "==================================" RESET "\n");

    printf("Input choice: ");
    scanf("%d", &choice);
    system("cls");

    if (choice == 1)
    {
        alldata();
    }
    else if (choice == 2)
    {
        daterange();
    }
}

void searchByType()
{
    struct dataSales data;

    FILE *sales = fopen("sales.txt", "r");
    if (sales == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    int found = 0;
    int count;
    char searchType[21];

    printf("Input car type to search: ");
    scanf(" %[^\n]", searchType);
    capital(searchType);
    system("cls");

    printf("===================================================================================================================================================\n");
    printf("                                              Search Results by Type: %s                                                                          \n", searchType);
    printf("===================================================================================================================================================\n");
    printf("| %s | %s | %-10s | %-7s | %s | %-5s | %-8s | %-8s | %s | %s | %-9s | %s |\n",
           "Transaction Date", "Customer", "Car Type", "Brand", "Car Name", "Year", "Fuel", "CC", "Transmission", "Quantity", "Price", "Total Price");
    printf("===================================================================================================================================================\n");

    while (fscanf(sales, "%2d%2d%4d,%100[^,],%15[^,],%15[^,],%d,%100[^,],%25[^,],%d,%15[^,],%d,%lf,%lf\n",
                  &data.time.transactionDay, &data.time.transactionMonth, &data.time.transactionYear,
                  data.customerName, data.carType, data.carBrand, &data.carYear, data.carName, data.fuelType, &data.engineDisplacement,
                  data.transmissionType, &data.price.quantity, &data.price.pricePerUnit, &data.price.totalPrice) != EOF)
    {
        if (strcmp(data.carType, searchType) == 0)
        {
            printf("| %02d/%02d/%-10.04d | %-8s | %-10s | %-7s | %-8s | %-5d | %-8s | %-8d | %-12s | %-8d | %-7.0lf | %-12.0lf|\n",
                   data.time.transactionDay, data.time.transactionMonth, data.time.transactionYear,
                   data.customerName, data.carType, data.carBrand, data.carName,
                   data.carYear, data.fuelType, data.engineDisplacement,
                   data.transmissionType, data.price.quantity, data.price.pricePerUnit, data.price.totalPrice);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No results found for type name: %s\n", searchType);
    }

    printf("===================================================================================================================================================\n");
    fclose(sales);
}

void searchByBrand()
{
    struct dataSales data;

    FILE *sales = fopen("sales.txt", "r");
    if (sales == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    int found = 0;
    int count;
    char searchBrand[51];

    printf("Input car brand to search: ");
    scanf(" %[^\n]", searchBrand);
    capital(searchBrand);
    system("cls");

    printf("===================================================================================================================================================\n");
    printf("                                             Search Results by Brand: %s                                                                          \n", searchBrand);
    printf("===================================================================================================================================================\n");
    printf("| %s | %s | %-10s | %-7s | %s | %-5s | %-8s | %-8s | %s | %s | %-9s | %s |\n",
           "Transaction Date", "Customer", "Car Type", "Brand", "Car Name", "Year", "Fuel", "CC", "Transmission", "Quantity", "Price", "Total Price");
    printf("===================================================================================================================================================\n");

    while (fscanf(sales, "%2d%2d%4d,%100[^,],%15[^,],%15[^,],%d,%100[^,],%25[^,],%d,%15[^,],%d,%lf,%lf\n",
                  &data.time.transactionDay, &data.time.transactionMonth, &data.time.transactionYear,
                  data.customerName, data.carType, data.carBrand, &data.carYear, data.carName, data.fuelType, &data.engineDisplacement,
                  data.transmissionType, &data.price.quantity, &data.price.pricePerUnit, &data.price.totalPrice) != EOF)
    {
        if (strcmp(data.carBrand, searchBrand) == 0)
        {
            printf("| %02d/%02d/%-10.04d | %-8s | %-10s | %-7s | %-8s | %-5d | %-8s | %-8d | %-12s | %-8d | %-7.0lf | %-12.0lf|\n",
                   data.time.transactionDay, data.time.transactionMonth, data.time.transactionYear,
                   data.customerName, data.carType, data.carBrand, data.carName,
                   data.carYear, data.fuelType, data.engineDisplacement,
                   data.transmissionType, data.price.quantity, data.price.pricePerUnit, data.price.totalPrice);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No results found for brand name: %s\n", searchBrand);
    }

    printf("===================================================================================================================================================\n");
    fclose(sales);
}

void searchByFuel()
{
    struct dataSales data;

    FILE *sales = fopen("sales.txt", "r");
    if (sales == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    int found = 0;
    int count;
    char searchFuel[21];

    printf("Input car fuel to search: ");
    scanf(" %[^\n]", searchFuel);
    capital(searchFuel);
    system("cls");

    printf("===================================================================================================================================================\n");
    printf("                                             Search Results by Fuel: %s                                                                           \n", searchFuel);
    printf("===================================================================================================================================================\n");
    printf("| %s | %s | %-10s | %-7s | %s | %-5s | %-8s | %-8s | %s | %s | %-9s | %s |\n",
           "Transaction Date", "Customer", "Car Type", "Brand", "Car Name", "Year", "Fuel", "CC", "Transmission", "Quantity", "Price", "Total Price");
    printf("===================================================================================================================================================\n");

    while (fscanf(sales, "%2d%2d%4d,%100[^,],%15[^,],%15[^,],%d,%100[^,],%25[^,],%d,%15[^,],%d,%lf,%lf\n",
                  &data.time.transactionDay, &data.time.transactionMonth, &data.time.transactionYear,
                  data.customerName, data.carType, data.carBrand, &data.carYear, data.carName, data.fuelType, &data.engineDisplacement,
                  data.transmissionType, &data.price.quantity, &data.price.pricePerUnit, &data.price.totalPrice) != EOF)
    {
        if (strcmp(data.fuelType, searchFuel) == 0)
        {
            printf("| %02d/%02d/%-10.04d | %-8s | %-10s | %-7s | %-8s | %-5d | %-8s | %-8d | %-12s | %-8d | %-7.0lf | %-12.0lf|\n",
                   data.time.transactionDay, data.time.transactionMonth, data.time.transactionYear,
                   data.customerName, data.carType, data.carBrand, data.carName,
                   data.carYear, data.fuelType, data.engineDisplacement,
                   data.transmissionType, data.price.quantity, data.price.pricePerUnit, data.price.totalPrice);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No results found for fuel name: %s\n", searchFuel);
    }

    printf("===================================================================================================================================================\n");
    fclose(sales);
}

void searchByTransmission()
{
    struct dataSales data;

    FILE *sales = fopen("sales.txt", "r");
    if (sales == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    int found = 0;
    int count;
    char searchTransmission[21];

    printf("Input car Transmission to search: ");
    scanf(" %[^\n]", searchTransmission);
    capital(searchTransmission);
    system("cls");

    printf("===================================================================================================================================================\n");
    printf("                                          Search Results by Transmission: %s                                                                      \n", searchTransmission);
    printf("===================================================================================================================================================\n");
    printf("| %s | %s | %-10s | %-7s | %s | %-5s | %-8s | %-8s | %s | %s | %-9s | %s |\n",
           "Transaction Date", "Customer", "Car Type", "Brand", "Car Name", "Year", "Fuel", "CC", "Transmission", "Quantity", "Price", "Total Price");
    printf("===================================================================================================================================================\n");

    while (fscanf(sales, "%2d%2d%4d,%100[^,],%15[^,],%15[^,],%d,%100[^,],%25[^,],%d,%15[^,],%d,%lf,%lf\n",
                  &data.time.transactionDay, &data.time.transactionMonth, &data.time.transactionYear,
                  data.customerName, data.carType, data.carBrand, &data.carYear, data.carName, data.fuelType, &data.engineDisplacement,
                  data.transmissionType, &data.price.quantity, &data.price.pricePerUnit, &data.price.totalPrice) != EOF)
    {
        if (strcmp(data.transmissionType, searchTransmission) == 0)
        {
            printf("| %02d/%02d/%-10.04d | %-8s | %-10s | %-7s | %-8s | %-5d | %-8s | %-8d | %-12s | %-8d | %-7.0lf | %-12.0lf|\n",
                   data.time.transactionDay, data.time.transactionMonth, data.time.transactionYear,
                   data.customerName, data.carType, data.carBrand, data.carName,
                   data.carYear, data.fuelType, data.engineDisplacement,
                   data.transmissionType, data.price.quantity, data.price.pricePerUnit, data.price.totalPrice);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No results found for transmission name: %s\n", searchTransmission);
    }

    printf("===================================================================================================================================================\n");
    fclose(sales);
}

void searchByCarName()
{
    struct dataSales data;

    FILE *sales = fopen("sales.txt", "r");
    if (sales == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    int found = 0;
    char searchCarName[101];

    printf("Input car name to search: ");
    scanf(" %[^\n]", searchCarName);
    capital(searchCarName);
    system("cls");

    printf("===================================================================================================================================================\n");
    printf("                                            Search Results by Car Name: %s                                                                        \n", searchCarName);
    printf("===================================================================================================================================================\n");
    printf("| %s | %s | %-10s | %-7s | %s | %-5s | %-8s | %-8s | %s | %s | %-9s | %s |\n",
           "Transaction Date", "Customer", "Car Type", "Brand", "Car Name", "Year", "Fuel", "CC", "Transmission", "Quantity", "Price", "Total Price");
    printf("===================================================================================================================================================\n");

    while (fscanf(sales, "%2d%2d%4d,%100[^,],%15[^,],%15[^,],%d,%100[^,],%25[^,],%d,%15[^,],%d,%lf,%lf\n",
                  &data.time.transactionDay, &data.time.transactionMonth, &data.time.transactionYear,
                  data.customerName, data.carType, data.carBrand, &data.carYear, data.carName, data.fuelType, &data.engineDisplacement,
                  data.transmissionType, &data.price.quantity, &data.price.pricePerUnit, &data.price.totalPrice) != EOF)
    {
        if (strcmp(data.carName, searchCarName) == 0)
        {
            printf("| %02d/%02d/%-10.04d | %-8s | %-10s | %-7s | %-8s | %-5d | %-8s | %-8d | %-12s | %-8d | %-7.0lf | %-12.0lf|\n",
                   data.time.transactionDay, data.time.transactionMonth, data.time.transactionYear,
                   data.customerName, data.carType, data.carBrand, data.carName,
                   data.carYear, data.fuelType, data.engineDisplacement,
                   data.transmissionType, data.price.quantity, data.price.pricePerUnit, data.price.totalPrice);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No results found for car name: %s\n", searchCarName);
    }

    printf("===================================================================================================================================================\n");
    fclose(sales);
}

void searchData()
{
    struct dataSales data;

    int choice;

    printf(BOLD "========== Search Data ==========" RESET "\n");
    printf("1. Search by Type\n");
    printf("2. Search by Brand\n");
    printf("3. Search by Fuel\n");
    printf("4. Search by Transmission\n");
    printf("5. Search by Car Name\n");
    printf(BOLD "==================================" RESET "\n");

    printf("Input choice: ");
    scanf("%d", &choice);
    system("cls");

    switch (choice)
    {
    case 1:
    {
        searchByType();
        break;
    }
    case 2:
    {
        searchByBrand();
        break;
    }
    case 3:
    {
        searchByFuel();
        break;
    }
    case 4:
    {
        searchByTransmission();
        break;
    }
    case 5:
    {
        searchByCarName();
        break;
    }
    default:
        printf("Invalid Choice\n");
    }
}

void sortbyType(struct dataSales data[])
{
    FILE *sales = fopen("sales.txt", "r");
    if (sales == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    struct dataSales temp;
    int n = 0;
    int choice;

    while (fscanf(sales, "%2d%2d%4d,%100[^,],%15[^,],%15[^,],%d,%100[^,],%25[^,],%d,%15[^,],%d,%lf,%lf\n",
                  &data[n].time.transactionDay, &data[n].time.transactionMonth, &data[n].time.transactionYear,
                  data[n].customerName, data[n].carType, data[n].carBrand, &data[n].carYear, data[n].carName,
                  data[n].fuelType, &data[n].engineDisplacement, &data[n].transmissionType,
                  &data[n].price.quantity, &data[n].price.pricePerUnit, &data[n].price.totalPrice) != EOF)
    {
        n++;
    }

    fclose(sales);

    printf(BOLD "========== Search Data ==========" RESET "\n");
    printf("1. Sort Ascending\n");
    printf("2. Sort Descending\n");
    printf(BOLD "==================================" RESET "\n");

    printf("Input choice: ");
    scanf("%d", &choice);
    system("cls");

    switch (choice)
    {
    case 1:
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (strcmp(data[j].carType, data[j + 1].carType) > 0)
                {
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
        break;
    case 2:
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (strcmp(data[j].carType, data[j + 1].carType) < 0)
                {
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
        break;
    default:
        printf("Oops! That's not a valid option.\n");
        break;
    }

    printf("===================================================================================================================================================\n");
    printf("                                                 Sorted Results by Car Type                                                                    \n");
    printf("===================================================================================================================================================\n");
    printf("| %s | %s | %-10s | %-7s | %s | %-5s | %-8s | %-8s | %s | %s | %-9s | %s |\n",
           "Transaction Date", "Customer", "Car Type", "Brand", "Car Name", "Year", "Fuel", "CC", "Transmission", "Quantity", "Price", "Total Price");
    printf("===================================================================================================================================================\n");

    for (int i = 0; i < n; i++)
    {
        printf("| %02d/%02d/%-10.04d | %-8s | %-10s | %-7s | %-8s | %-5d | %-8s | %-8d | %-12s | %-8d | %-7.0lf | %-12.0lf|\n",
               data[i].time.transactionDay, data[i].time.transactionMonth, data[i].time.transactionYear,
               data[i].customerName, data[i].carType, data[i].carBrand, data[i].carName,
               data[i].carYear, data[i].fuelType, data[i].engineDisplacement,
               data[i].transmissionType, data[i].price.quantity, data[i].price.pricePerUnit, data[i].price.totalPrice);
    }
    printf("===================================================================================================================================================\n");
}

void sortbyDate(struct dataSales data[]) {
    FILE *sales = fopen("sales.txt", "r");
    if (sales == NULL){
		printf("Error opening file\n");
		return;
	}
	
	struct dataSales temp;
    int n = 0;
    int choice;
    
    while (fscanf(sales, "%2d%2d%4d,%100[^,],%15[^,],%15[^,],%d,%100[^,],%25[^,],%d,%15[^,],%d,%lf,%lf\n",
                &data[n].time.transactionDay, &data[n].time.transactionMonth, &data[n].time.transactionYear,
                data[n].customerName, data[n].carType, data[n].carBrand, &data[n].carYear,  data[n].carName, 
                data[n].fuelType, &data[n].engineDisplacement,&data[n].transmissionType, 
                &data[n].price.quantity, &data[n].price.pricePerUnit, &data[n].price.totalPrice) != EOF) {
        n++;
    }

    fclose(sales);

    printf(BOLD "========== Search Data ==========" RESET "\n");
    printf("1. Sort Ascending\n");
    printf("2. Sort Descending\n");
    printf(BOLD "==================================" RESET "\n");

    printf("Input choice: ");
    scanf("%d", &choice);
    system("cls");

    switch (choice) {
    case 1:
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (compareDates(data[j].time.transactionDay, data[j].time.transactionMonth, data[j].time.transactionYear,
                                 data[j + 1].time.transactionDay, data[j + 1].time.transactionMonth, data[j + 1].time.transactionYear) > 0) {
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
        break;
    case 2:
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (compareDates(data[j].time.transactionDay, data[j].time.transactionMonth, data[j].time.transactionYear,
                                 data[j + 1].time.transactionDay, data[j + 1].time.transactionMonth, data[j + 1].time.transactionYear) < 0) {
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
        break;
    default:
        printf("Oops! That's not a valid option.\n");
        break;
    }

    printf("===================================================================================================================================================\n");
    printf("                                                 Sorted Results by Transaction Date                                                                \n");
    printf("===================================================================================================================================================\n");
    printf("| %s | %s | %-10s | %-7s | %s | %-5s | %-8s | %-8s | %s | %s | %-9s | %s |\n",
           "Transaction Date", "Customer", "Car Type", "Brand", "Car Name", "Year", "Fuel", "CC", "Transmission", "Quantity", "Price", "Total Price");
    printf("===================================================================================================================================================\n");

    for (int i = 0; i < n; i++) {
        printf("| %02d/%02d/%-10.04d | %-8s | %-10s | %-7s | %-8s | %-5d | %-8s | %-8d | %-12s | %-8d | %-7.0lf | %-12.0lf|\n",
               data[i].time.transactionDay, data[i].time.transactionMonth, data[i].time.transactionYear,
               data[i].customerName, data[i].carType, data[i].carBrand, data[i].carName,
               data[i].carYear, data[i].fuelType, data[i].engineDisplacement,
               data[i].transmissionType, data[i].price.quantity, data[i].price.pricePerUnit, data[i].price.totalPrice);
    }
    printf("===================================================================================================================================================\n");
}

void sortbyCustomerName(struct dataSales data[]){
	FILE *sales = fopen("sales.txt", "r");
	if (sales == NULL){
		printf("Error opening file\n");
		return;
	}
	
	struct dataSales temp;
    int n = 0;
    int choice;

    while (fscanf(sales, "%2d%2d%4d,%100[^,],%15[^,],%15[^,],%d,%100[^,],%25[^,],%d,%15[^,],%d,%lf,%lf\n",
                &data[n].time.transactionDay, &data[n].time.transactionMonth, &data[n].time.transactionYear,
                data[n].customerName, data[n].carType, data[n].carBrand, &data[n].carYear,  data[n].carName, 
                data[n].fuelType, &data[n].engineDisplacement,&data[n].transmissionType, 
                &data[n].price.quantity, &data[n].price.pricePerUnit, &data[n].price.totalPrice) != EOF) {
        n++;
    }

    fclose(sales);

    printf(BOLD "========== Search Data ==========" RESET "\n");
    printf("1. Sort Ascending\n");
    printf("2. Sort Descending\n");
    printf(BOLD "==================================" RESET "\n");

    printf("Input choice: ");
    scanf("%d", &choice);
    system("cls");
    
    switch (choice) {
    case 1:
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (strcmp(data[j].customerName, data[j + 1].customerName) > 0) {
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
        break;
    case 2:
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (strcmp(data[j].customerName, data[j + 1].customerName) < 0) {
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
        break;
    default:
        printf("Oops! That's not a valid option.\n");
        break;
    }
    
    printf("===================================================================================================================================================\n");
    printf("                                                 Sorted Results by Customer Name                                                                   \n");
    printf("===================================================================================================================================================\n");
    printf("| %s | %s | %-10s | %-7s | %s | %-5s | %-8s | %-8s | %s | %s | %-9s | %s |\n",
           "Transaction Date", "Customer", "Car Type", "Brand", "Car Name", "Year", "Fuel", "CC", "Transmission", "Quantity", "Price", "Total Price");
    printf("===================================================================================================================================================\n");

    for (int i = 0; i < n; i++) {
        printf("| %02d/%02d/%-10.04d | %-8s | %-10s | %-7s | %-8s | %-5d | %-8s | %-8d | %-12s | %-8d | %-7.0lf | %-12.0lf|\n",
               data[i].time.transactionDay, data[i].time.transactionMonth, data[i].time.transactionYear,
               data[i].customerName, data[i].carType, data[i].carBrand, data[i].carName,
               data[i].carYear, data[i].fuelType, data[i].engineDisplacement,
               data[i].transmissionType, data[i].price.quantity, data[i].price.pricePerUnit, data[i].price.totalPrice);
    }
    printf("===================================================================================================================================================\n");
}

void sortbyCarName(struct dataSales data[]){
	FILE *sales = fopen("sales.txt", "r");
	if (sales == NULL){
		printf("Error opening file\n");
		return;
	}
	
	struct dataSales temp;
    int n = 0;
    int choice;

    while (fscanf(sales, "%2d%2d%4d,%100[^,],%15[^,],%15[^,],%d,%100[^,],%25[^,],%d,%15[^,],%d,%lf,%lf\n",
                &data[n].time.transactionDay, &data[n].time.transactionMonth, &data[n].time.transactionYear,
                data[n].customerName, data[n].carType, data[n].carBrand, &data[n].carYear,  data[n].carName, 
                data[n].fuelType, &data[n].engineDisplacement,&data[n].transmissionType, 
                &data[n].price.quantity, &data[n].price.pricePerUnit, &data[n].price.totalPrice) != EOF) {
        n++;
    }

    fclose(sales);

    printf(BOLD "========== Search Data ==========" RESET "\n");
    printf("1. Sort Ascending\n");
    printf("2. Sort Descending\n");
    printf(BOLD "==================================" RESET "\n");

    printf("Input choice: ");
    scanf("%d", &choice);
    system("cls");
    
    switch (choice) {
    case 1:
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (strcmp(data[j].carName, data[j + 1].carName) > 0) {
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
        break;
    case 2:
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (strcmp(data[j].carName, data[j + 1].carName) < 0) {
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
        break;
    default:
        printf("Oops! That's not a valid option.\n");
        break;
    }
    
    printf("===================================================================================================================================================\n");
    printf("                                                 Sorted Results by Car Name                                                                   \n");
    printf("===================================================================================================================================================\n");
    printf("| %s | %s | %-10s | %-7s | %s | %-5s | %-8s | %-8s | %s | %s | %-9s | %s |\n",
           "Transaction Date", "Customer", "Car Type", "Brand", "Car Name", "Year", "Fuel", "CC", "Transmission", "Quantity", "Price", "Total Price");
    printf("===================================================================================================================================================\n");

    for (int i = 0; i < n; i++) {
        printf("| %02d/%02d/%-10.04d | %-8s | %-10s | %-7s | %-8s | %-5d | %-8s | %-8d | %-12s | %-8d | %-7.0lf | %-12.0lf|\n",
               data[i].time.transactionDay, data[i].time.transactionMonth, data[i].time.transactionYear,
               data[i].customerName, data[i].carType, data[i].carBrand, data[i].carName,
               data[i].carYear, data[i].fuelType, data[i].engineDisplacement,
               data[i].transmissionType, data[i].price.quantity, data[i].price.pricePerUnit, data[i].price.totalPrice);
    }
    printf("===================================================================================================================================================\n");
}

void sortbyBrand(struct dataSales data[]){
	FILE *sales = fopen("sales.txt", "r");
	if (sales == NULL){
		printf("Error opening file\n");
		return;
	}
	
	struct dataSales temp;
    int n = 0;
    int choice;

    while (fscanf(sales, "%2d%2d%4d,%100[^,],%15[^,],%15[^,],%d,%100[^,],%25[^,],%d,%15[^,],%d,%lf,%lf\n",
                &data[n].time.transactionDay, &data[n].time.transactionMonth, &data[n].time.transactionYear,
                data[n].customerName, data[n].carType, data[n].carBrand, &data[n].carYear,  data[n].carName, 
                data[n].fuelType, &data[n].engineDisplacement,&data[n].transmissionType, 
                &data[n].price.quantity, &data[n].price.pricePerUnit, &data[n].price.totalPrice) != EOF) {
        n++;
    }

    fclose(sales);

    printf(BOLD "========== Search Data ==========" RESET "\n");
    printf("1. Sort Ascending\n");
    printf("2. Sort Descending\n");
    printf(BOLD "==================================" RESET "\n");

    printf("Input choice: ");
    scanf("%d", &choice);
    system("cls");
    
    switch (choice) {
    case 1:
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (strcmp(data[j].carBrand, data[j + 1].carBrand) > 0) {
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
        break;
    case 2:
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (strcmp(data[j].carBrand, data[j + 1].carBrand) < 0) {
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
        break;
    default:
        printf("Oops! That's not a valid option.\n");
        break;
    }
    
    printf("===================================================================================================================================================\n");
    printf("                                                 Sorted Results by Car Brand                                                                   \n");
    printf("===================================================================================================================================================\n");
    printf("| %s | %s | %-10s | %-7s | %s | %-5s | %-8s | %-8s | %s | %s | %-9s | %s |\n",
           "Transaction Date", "Customer", "Car Type", "Brand", "Car Name", "Year", "Fuel", "CC", "Transmission", "Quantity", "Price", "Total Price");
    printf("===================================================================================================================================================\n");

    for (int i = 0; i < n; i++) {
        printf("| %02d/%02d/%-10.04d | %-8s | %-10s | %-7s | %-8s | %-5d | %-8s | %-8d | %-12s | %-8d | %-7.0lf | %-12.0lf|\n",
               data[i].time.transactionDay, data[i].time.transactionMonth, data[i].time.transactionYear,
               data[i].customerName, data[i].carType, data[i].carBrand, data[i].carName,
               data[i].carYear, data[i].fuelType, data[i].engineDisplacement,
               data[i].transmissionType, data[i].price.quantity, data[i].price.pricePerUnit, data[i].price.totalPrice);
    }
    printf("===================================================================================================================================================\n");
}

void sortData()
{
    int choice;
    struct dataSales data[50];

    printf(BOLD "========== Sort Data ==========" RESET "\n");
    printf("1. Sort by Transaction Date\n");
    printf("2. Sort by Customer Name\n");
    printf("3. Sort by Car Type\n");
    printf("4. Sort by Car Brand\n");
    printf("5. Sort by Car Name\n");
    printf(BOLD "===============================" RESET "\n");

    printf("Input choice: ");
    scanf(" %d", &choice);
    system("cls");

    switch (choice)
    {
    case 1:
        sortbyDate(data);
        break;
    case 2:
        sortbyCustomerName(data);
        break;
    case 3:
        sortbyType(data);
        break;
    case 4:
        sortbyBrand(data);
        break;
    case 5:
        sortbyCarName(data);
        break;
    default:
        printf("Oops! That's not a valid option.\n");
        break;
    }
}

int main()
{
    int choice;

    displayIntroduction();

    do
    {
        printf(BOLD "========== MENU ==========" RESET "\n");
        printf("1. Entry Sales Data\n");
        printf("2. Display Sales Data\n");
        printf("3. Search Sales Data\n");
        printf("4. Sort Sales Data\n");
        printf("0. Exit\n");
        printf(BOLD "==========================" RESET "\n");

        printf("Input choice: ");
        scanf("%d", &choice);
        system("cls");

        switch (choice)
        {
        case 1:
            entryData();
            break;
        case 2:
            displayData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            sortData();
            break;
        case 0:
            printf("Success Exit The Program!!");
            break;
        default:
            printf("Oops! That's not a valid option.\n");
            break;
        }
    } while (choice != 0);
    return 0;
}
