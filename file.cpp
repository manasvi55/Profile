#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 
#include <sstream>

using namespace std;


struct Profile {
    string name;
    string courses;
    string computerLanguages;
    string personalProject;
    string otherInterests;
    string foreignLanguages;
    float marks10th;
    float marks12th;
    float cgpa;
    string certificates;
    bool hasInternship;
    bool hasJob;
    string phoneNumber;
    int age;
    string email;
    int previousJobExp;
};


void createProfile() {
    ofstream outfile("profiles.txt", ios::app);
    if (!outfile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    Profile newProfile;
    cout << "Enter name: ";
    getline(cin, newProfile.name);

    cout << "Enter courses interested (comma-separated): ";
    getline(cin, newProfile.courses);

    cout << "Enter certificates achieved (comma-separated): ";
    getline(cin, newProfile.certificates);

    cout << "Enter 10-digit phone number: ";
    getline(cin, newProfile.phoneNumber);
    while (newProfile.phoneNumber.length() != 10) {
        cout << "Invalid phone number! Please enter a 10-digit phone number: ";
        getline(cin, newProfile.phoneNumber);
    }

    cout << "Enter age: ";
    cin >> newProfile.age;
    cin.ignore();

    while (newProfile.age <= 0 || newProfile.age < 18) {
        if (newProfile.age <= 0) {
            cout << "Invalid age! Please enter a valid age: ";
        } else {
            cout << "You must be at least 18 years old to be considered for a job. Please enter a valid age: ";
        }
        cin >> newProfile.age;
        cin.ignore();
    }

    if (newProfile.age >= 18) {
        char jobExpChoice;
        cout << "Do you have any previous job experience? (Y/N): ";
        cin >> jobExpChoice;
        cin.ignore();

        if (jobExpChoice == 'Y' || jobExpChoice == 'y') {
            cout << "Enter previous job experience time (in months): ";
            cin >> newProfile.previousJobExp;
            cin.ignore();
        }
    }


    cout << "Enter email ID: ";
    string enteredEmail;
    getline(cin, enteredEmail);

    while (enteredEmail.find("@gmail.com") == string::npos) {
        cout << "Invalid email format! Please enter an email with @gmail.com domain: ";
        getline(cin, enteredEmail);
    }

    newProfile.email = enteredEmail;

     cout << "Enter marks of 10th grade: ";
    cin >> newProfile.marks10th;

    
    const float passingMarks10th = 40.0; 
    if (newProfile.marks10th < passingMarks10th) {
        cout << "Sorry, you have failed in 10th grade. Job cannot be offered." << endl;
        return; 
    }

    cout << "Enter marks of 12th grade: ";
    cin >> newProfile.marks12th;

   
    const float passingMarks12th = 40.0; 
    if (newProfile.marks12th < passingMarks12th) {
        cout << "Sorry, you have failed in 12th grade. Job cannot be offered." << endl;
        return; 
    }
     cout << "Enter CGPA: ";
    cin >> newProfile.cgpa;

    cin.ignore(); 

    cout << "Enter computer languages known (comma-separated): ";
    getline(cin, newProfile.computerLanguages);

    cout << "Enter details about personal project: ";
    getline(cin, newProfile.personalProject);

    cout << "Enter other interests: ";
    getline(cin, newProfile.otherInterests);

    cout << "Enter foreign languages known (comma-separated): ";
    getline(cin, newProfile.foreignLanguages);


    char choice;
    cout << "Do you have any internship experience? (Y/N): ";
    cin >> choice;
    newProfile.hasInternship = (choice == 'Y' || choice == 'y');

    

    outfile << newProfile.name << "|" << newProfile.courses << "|" << newProfile.certificates << "|" << newProfile.hasInternship << "|" << newProfile.hasJob << "|"
            << newProfile.phoneNumber << "|" << newProfile.age << "|" << newProfile.email << "|" << newProfile.previousJobExp << "\n";
    outfile.close();
    cout << "Profile created successfully!" << endl;
}


void displayProfiles() {
    ifstream infile("profiles.txt");
    if (!infile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string name, courses, certificates, hasInternship, hasJob, phoneNumber, age, email, previousJobExp;

        getline(ss, name, '|');
        getline(ss, courses, '|');
        getline(ss, certificates, '|');
        getline(ss, hasInternship, '|');
        getline(ss, hasJob, '|');
        getline(ss, phoneNumber, '|');
        getline(ss, age, '|');
        getline(ss, email, '|');
       

        cout << "Name: " << name << endl;
        cout << "Courses: " << courses << endl;
        cout << "Certificates: " << certificates << endl;
        cout << "Internship Experience: " << (hasInternship == "1" ? "Yes" : "No") << endl;
        cout << "Job Experience: " << (hasJob == "1" ? "Yes" : "No") << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Age: " << age << endl;
        cout << "Email ID: " << email << endl;
       
        cout << "---------------------" << endl;
    }
    infile.close();
}


void recommendCompanies(Profile profile) {
    if (profile.certificates.find(',') != string::npos) {
        int certificatesCount = count(profile.certificates.begin(), profile.certificates.end(), ',') + 1;
        if (certificatesCount < 3) {
            cout << "Insufficient certificates for job or internship recommendations." << endl;
            return;
        }
    } else {
        if (profile.certificates.empty()) {
            cout << "No certificates provided for job or internship recommendations." << endl;
            return;
        }
    }

    if (profile.computerLanguages.find(',') != string::npos) {
        int languagesCount = count(profile.computerLanguages.begin(), profile.computerLanguages.end(), ',') + 1;
        if (languagesCount < 2) {
            cout << "Insufficient computer languages known for job or internship recommendations." << endl;
            return;
        }
    } else {
        if (profile.computerLanguages.empty()) {
            cout << "No computer languages provided for job or internship recommendations." << endl;
            return;
        }
    }

    if (profile.cgpa < 6.0) {
        cout << "CGPA below 6.0. Not eligible for job or internship recommendations." << endl;
        return;
    }

    cout << "Company recommendations based on your achievements: " << endl;
    
    cout << "Infosys" << endl;
    cout << "Cognizant" << endl;
    cout << "Persistent" << endl;
   
}




int main() {
    int choice;
    do {
        cout << "Menu:\n1. Create Profile\n2. Display Profiles\n3. Search Profiles by Certificates\n4. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                createProfile();
                break;
            case 2:
                displayProfiles();
                break;
            case 3: {
                ifstream infile("profiles.txt");
                if (!infile) {
                    cerr << "Error opening the file." << endl;
                    return -1;
                }

                string searchTerm;
                cout << "Enter certificates to search: ";
                getline(cin, searchTerm);

                string line;
                bool found = false;
                while (getline(infile, line)) {
                    stringstream ss(line);
                    string name, courses, certificates, hasInternship, hasJob, phoneNumber, age, email, previousJobExp;

                    getline(ss, name, '|');
                    getline(ss, courses, '|');
                    getline(ss, certificates, '|');
                    getline(ss, hasInternship, '|');
                    getline(ss, hasJob, '|');
                    getline(ss, phoneNumber, '|');
                    getline(ss, age, '|');
                    getline(ss, email, '|');
                    getline(ss, previousJobExp, '|');

                    if (certificates.find(searchTerm) != string::npos) {
                        found = true;
                        cout << "Name: " << name << endl;
                        cout << "Courses: " << courses << endl;
                        cout << "Certificates: " << certificates << endl;
                        cout << "Internship Experience: " << (hasInternship == "1" ? "Yes" : "No") << endl;
                        cout << "Job Experience: " << (hasJob == "1" ? "Yes" : "No") << endl;
                        cout << "Phone Number: " << phoneNumber << endl;
                        cout << "Age: " << age << endl;
                        cout << "Email ID: " << email << endl;
                        cout << "Previous Job Experience (months): " << previousJobExp << endl;
                        cout << "---------------------" << endl;
                    }
                }

                if (!found) {
                    cout << "No profiles found with the given certificate." << endl;
                }
                infile.close();
                break;
            }
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

        if (choice != 4) {
            char interestChoice;
            cout << "Are you interested in company recommendations based on your achievements? (Y/N): ";
            cin >> interestChoice;
            cin.ignore();

           if (interestChoice == 'Y' || interestChoice == 'y') {
    ifstream infile("profiles.txt");
    if (!infile) {
        cerr << "Error opening the file." << endl;
        return -1;
    }

    Profile currentProfile;
    bool profileFound = false;
    string line;
    cout << "Enter your name to get recommendations: ";
    string inputName;
    getline(cin, inputName);

    while (getline(infile, line)) {
        stringstream ss(line);
        string name, courses, certificates, hasInternship, hasJob, phoneNumber, age, email, previousJobExp;

        getline(ss, name, '|');
        getline(ss, courses, '|');
        getline(ss, certificates, '|');
        getline(ss, hasInternship, '|');
        getline(ss, hasJob, '|');
        getline(ss, phoneNumber, '|');
        getline(ss, age, '|');
        getline(ss, email, '|');
        getline(ss, previousJobExp, '|');

       if (name == inputName) {
    profileFound = true;
    currentProfile.name = name;
    currentProfile.courses = courses;
    currentProfile.certificates = certificates;
    currentProfile.hasInternship = (hasInternship == "1");
    currentProfile.hasJob = (hasJob == "1");
    currentProfile.phoneNumber = phoneNumber;
    currentProfile.email = email;

    try {
        if (!age.empty() && !previousJobExp.empty()) {
            currentProfile.age = stoi(age);
            currentProfile.previousJobExp = stoi(previousJobExp);
        } else {
            cerr << "Age or previous job experience data is missing." << endl;
            return -1;
        }
    } catch (const std::invalid_argument& e) {
        cerr << "Error converting age or previous job experience to integer: " << e.what() << endl;
        return -1;
    }
    break;
}

    }
    infile.close();

    if (profileFound) {
        recommendCompanies(currentProfile);
    } else {
        cout << "Profile not found!" << endl;
    }
} else {
    cout << "Exiting program. Goodbye!" << endl;
    choice = 4;
 }
        }
    } while (choice != 4);

    return 0;
}
