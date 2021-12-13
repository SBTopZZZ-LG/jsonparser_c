#include <stdio.h>

#include "../jsonparser.h"

// Structure prototypes
struct PersonSocials;
struct PersonDetails;
struct Person;

// Struct definitions
struct PersonSocials
{
    char linkedin[1024];
    char instagram[1024];
    char facebook[1024];
    char github[1024];
};
struct PersonDetails
{
    char bio[1024];
    struct PersonSocials socials;
};
struct Person
{
    int id;
    char name[100];
    char email[100];
    long int phoneNumber;
    struct Collection favouriteColours; // Array
    struct Collection favouriteNumbers; // Array
    struct PersonDetails details;
};

// Sample function prototypes
void readSave();
void loadPrint();

int main()
{
    readSave();
    loadPrint();

    return 0;
}

// Sample function definitions
void readSave()
{
    // Read information from user

    struct Person persons[2];

    printf("----- Enter details of two persons -----\n\n");

    for (int i = 0; i < 2; i++)
    {
        initializeCollection(&persons[i].favouriteColours); // Initialize a collection object
        initializeCollection(&persons[i].favouriteNumbers); // Initialize a collection object

        // Read & Set values
        persons[i].id = i + 1;

        printf("Enter person's name: ");
        scanf("%s", persons[i].name);

        printf("Enter person's email: ");
        scanf("%s", persons[i].email);

        printf("Enter person's phone number: ");
        scanf("%ld", &persons[i].phoneNumber);

        printf("Enter person's three favourite colours: ");
        char temp[COLLECTION_STRING_SIZE];
        for (int j = 0; j < 3; j++)
        {
            scanf("%s", temp);
            pushString_collection(&persons[i].favouriteColours, temp);
        }

        printf("Enter person's three favourite numbers: ");
        for (int j = 0; j < 3; j++)
        {
            int temp2;
            scanf("%d", &temp2);
            pushInt32_collection(&persons[i].favouriteNumbers, temp2);
        }

        printf("Enter person's bio: ");
        scanf("%s", persons[i].details.bio);

        printf("Enter person's linkedin: ");
        scanf("%s", persons[i].details.socials.linkedin);

        printf("Enter person's instagram: ");
        scanf("%s", persons[i].details.socials.instagram);

        printf("Enter person's facebook: ");
        scanf("%s", persons[i].details.socials.facebook);

        printf("Enter person's github: ");
        scanf("%s", persons[i].details.socials.github);
        // Read & Set values

        printf("\n");
    }

    /*
        Refer data.json
    */

    // Translate to json and stringify
    struct Json json;      // Declare Json object
    initializeJson(&json); // Initialize the json object

    struct Collection data;      // Json contains a key called "data", which holds a array (Collection) of Json objects
    initializeCollection(&data); // Initialize the collection object

    for (int i = 0; i < 2; i++)
    {
        struct Json person;      // Represents a Json object in the "data" Collection
        initializeJson(&person); // Initialize the json object

        // Put data into the json object
        putUInt8_json(&person, "id", (uint8_t)persons[i].id);
        putString_json(&person, "name", persons[i].name);
        putString_json(&person, "email", persons[i].email);
        putInt64_json(&person, "phoneNumber", persons[i].phoneNumber);

        struct Collection person_favColours;      // Represents the "favouriteColours" array (Collection) inside the json object "person"
        initializeCollection(&person_favColours); // Initialize the collection object

        // Put data into the collection object
        for (int j = 0; j < persons[i].favouriteColours.length; j++)
            pushString_collection(&person_favColours, getString_collection(&persons[i].favouriteColours, j)->str);

        struct Collection person_favNumbers;      // Represents the "favouriteNumbers" array (Collection) inside the json object "person"
        initializeCollection(&person_favNumbers); // Initialize the collection object

        // Put data into the collection object
        for (int j = 0; j < persons[i].favouriteNumbers.length; j++)
            pushInt32_collection(&person_favNumbers, getInt32_collection(&persons[i].favouriteNumbers, j));

        struct Json person_details;      // Represents the "details" json (Json) inside the json object "person"
        initializeJson(&person_details); // Initialize the json object

        // Put data into the json object
        putString_json(&person_details, "bio", persons[i].details.bio);

        struct Json person_details_socials;      // Represents the "socials" json (Json) inside the json object "details"
        initializeJson(&person_details_socials); // Initialize the json object

        // Put data into the json object
        putString_json(&person_details_socials, "linkedin", persons[i].details.socials.linkedin);
        putString_json(&person_details_socials, "instagram", persons[i].details.socials.instagram);
        putString_json(&person_details_socials, "facebook", persons[i].details.socials.facebook);
        putString_json(&person_details_socials, "github", persons[i].details.socials.github);

        // Link "favouriteColours" and "favouriteNumbers" collection objects under "person" json object
        putArray_json(&person, "favouriteColours", &person_favColours);
        putArray_json(&person, "favouriteNumbers", &person_favNumbers);

        // Link "socials" json object under "details" json object
        putJsonObject_json(&person_details, "socials", &person_details_socials);
        // Link "details" json object under "person" json object
        putJsonObject_json(&person, "details", &person_details);

        // Link "person" json object under "data" collection object
        pushJsonObject_collection(&data, &person);

        // Clear memory by clearing json after use
        clearJson(&person);
    }

    // Link "data" collection object under main json object
    putArray_json(&json, "data", &data);

    // Stringify
    char converted[JSON_STRINGIFY_SIZE];
    stringifyJson(&json, converted); // Converts the entire structure into a parseable string

    // Clear memory by clearing json after use
    clearJson(&json);

    // Write to file and save
    FILE *fp = fopen("data.json", "w");
    fprintf(fp, "%s", converted);
    fclose(fp);
}
void loadPrint()
{
    // Load data from file
    FILE *fp = fopen("data.json", "r");
    if (!fp)
    {
        printf("File not found!\n");
        return;
    }
    char data[JSON_STRINGIFY_SIZE];
    int index;
    char ch;
    while ((ch = fgetc(fp)) != EOF)
        data[index++] = ch;
    data[index] = '\0';

    // Unstringify to json
    struct Json parsed;             // Declare Json object "parsed" that will hold the parsed content after unstringifying
    unstringifyJson(data, &parsed); // Parse the string

    // Declare and set values
    struct Person persons[2];

    // Stores reference to the "data" collection object in the main json object
    struct Collection *json_persons = &getArray_json(&parsed, "data")->arr;

    for (int i = 0; i < json_persons->length; i++)
    {
        // Stores reference to ith json object in the "data" collection object
        struct Json *json_person = &getJsonObject_collection(json_persons, i)->jsonObject;

        // Read and copy values
        persons[i].id = getInt32_json(json_person, "id");

        strcpy(persons[i].name, getString_json(json_person, "name")->str);
        strcpy(persons[i].email, getString_json(json_person, "email")->str);

        persons[i].phoneNumber = getInt64_json(json_person, "phoneNumber");

        // Stores reference to the "favouriteColours" collection object in the "json_person" json object
        struct Collection *json_person_favColours = &getArray_json(json_person, "favouriteColours")->arr;

        // Read and copy values
        for (int j = 0; j < json_person_favColours->length; j++)
            pushString_collection(&persons[i].favouriteColours, getString_collection(json_person_favColours, j)->str);

        // Stores reference to the "favouriteNumbers" collection object in the "json_person" json object
        struct Collection *json_person_favNumbers = &getArray_json(json_person, "favouriteNumbers")->arr;

        // Read and copy values
        for (int j = 0; j < json_person_favColours->length; j++)
            pushInt32_collection(&persons[i].favouriteNumbers, getInt32_collection(json_person_favNumbers, j));

        // Stores reference to the "details" json object in the "json_person" json object
        struct Json *json_person_details = getJsonObject_json(json_person, "details");

        // Read and copy values
        strcpy(persons[i].details.bio, getString_json(json_person_details, "bio")->str);

        // Stores reference to the "socials" json object in the "json_person_details" json object
        struct Json *json_person_details_socials = getJsonObject_json(json_person_details, "socials");

        // Read and copy values
        strcpy(persons[i].details.socials.linkedin, getString_json(json_person_details_socials, "linkedin")->str);
        strcpy(persons[i].details.socials.instagram, getString_json(json_person_details_socials, "instagram")->str);
        strcpy(persons[i].details.socials.facebook, getString_json(json_person_details_socials, "facebook")->str);
        strcpy(persons[i].details.socials.github, getString_json(json_person_details_socials, "github")->str);
    }

    // Clear memory by clearing json
    clearJson(&parsed);

    // Print loaded structures
    printf("----- Loaded person profiles -----\n\n");

    for (int i = 0; i < 2; i++)
    {
        struct Person *person = &persons[i];

        printf("Id: %d\nName: %s\nEmail: %s\nPhone Number: %ld\nFavourite Colours: ", person->id, person->name, person->email, person->phoneNumber);
        for (int j = 0; j < person->favouriteColours.length; j++)
            printf("%s ", getString_collection(&person->favouriteColours, j)->str);
        printf("\nFavourite Numbers: ");
        for (int j = 0; j < person->favouriteNumbers.length; j++)
            printf("%d ", getInt32_collection(&person->favouriteNumbers, j));
        printf("\nDetails:\n\tBio: %s\n\tSocials: \n\t\tLinkedIn: %s\n\t\tInstagram: %s\n\t\tFacebook: %s\n\t\tGithub: %s\n",
               person->details.bio, person->details.socials.linkedin, person->details.socials.instagram, person->details.socials.facebook, person->details.socials.github);
    }
}