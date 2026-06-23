#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

// ─────────────────────── State flags (sequence enforcement) ──────────────────────────
bool customerEntered = false;
bool flightBooked    = false;

// ──────────────────────────────── Customer ──────────────────────────────────

class Customer {
private:
    string name;
    string gender;
    int    customerId;
    int    age;
    string address;

public:
    void enterDetails() {
        cout << "\nEnter Customer ID: ";
        while (!(cin >> customerId) || customerId <= 0) {
            cout << "  [!] Invalid ID. Enter a positive number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Name        : ";
        getline(cin, name);

        cout << "Enter Age         : ";
        while (!(cin >> age) || age <= 0 || age > 120) {
            cout << "  [!] Invalid age (1-120): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Address     : ";
        getline(cin, address);

        cout << "Enter Gender (Male/Female/Other): ";
        getline(cin, gender);

        cout << "\n  [✓] Customer details saved successfully.\n";
    }

    int    getCustomerId() const { return customerId; }
    string getName()       const { return name; }
    int    getAge()        const { return age; }
    string getAddress()    const { return address; }
    string getGender()     const { return gender; }

    void displayDetails() const {
        cout << "\n+------------------------------------------+\n";
        cout << "|          CUSTOMER INFORMATION            |\n";
        cout << "+------------------------------------------+\n";
        cout << "  Customer ID : " << customerId << "\n";
        cout << "  Name        : " << name       << "\n";
        cout << "  Age         : " << age        << "\n";
        cout << "  Gender      : " << gender     << "\n";
        cout << "  Address     : " << address    << "\n";
        cout << "+------------------------------------------+\n";
    }
};

// ────────────────────────────── Flight ─────────────────────────────────

class Flight {
private:
    string flightCode;
    string destination;
    string duration;
    double cost;

public:
    Flight(const string& code, const string& dest,
           const string& dur, double price)
        : flightCode(code), destination(dest),
          duration(dur), cost(price) {}

    void displayFlightDetails(int index) const {
        cout << "  " << index << ".  Flight: " << flightCode
             << "   From: Karachi, Pakistan   To: " << left << setw(16) << destination
             << "  Duration: " << setw(8) << duration
             << "  Price: PKR " << fixed << setprecision(0) << cost << "\n";
    }

    double getCost()        const { return cost; }
    string getDestination() const { return destination; }
    string getFlightCode()  const { return flightCode; }
    string getDuration()    const { return duration; }
};

// ──────────────────────────────── Ticket ─────────────────────────────────────

class Ticket {
private:
    string customerName;
    int    customerId;
    int    customerAge;
    string customerGender;
    string destination;
    string flightCode;
    string duration;
    double totalCost;

public:
    Ticket(const Customer& c, const Flight& f)
        : customerName(c.getName()),
          customerId(c.getCustomerId()),
          customerAge(c.getAge()),
          customerGender(c.getGender()),
          destination(f.getDestination()),
          flightCode(f.getFlightCode()),
          duration(f.getDuration()),
          totalCost(f.getCost()) {}

    string buildReceipt() const {
        string r = "";
        r += "\n";
        r += "  ****************************************************\n";
        r += "  *                                                  *\n";
        r += "  *             XYZ AIRLINES                         *\n";
        r += "  *          BOARDING PASS / E-TICKET                *\n";
        r += "  *                                                  *\n";
        r += "  ****************************************************\n";
        r += "  *                                                  *\n";
        r += "  *  PASSENGER  : " + customerName + "\n";
        r += "  *  CUST ID    : " + to_string(customerId) + "\n";
        r += "  *  AGE        : " + to_string(customerAge) + "\n";
        r += "  *  GENDER     : " + customerGender + "\n";
        r += "  *                                                  *\n";
        r += "  *--------------------------------------------------*\n";
        r += "  *                                                  *\n";
        r += "  *  FLIGHT NO  : " + flightCode + "\n";
        r += "  *  DEST       : " + destination + "\n";
        r += "  *  DURATION   : " + duration + "\n";
        r += "  *                                                  *\n";
        r += "  *--------------------------------------------------*\n";
        r += "  *                                                  *\n";

        // Format cost manually for the receipt string
        string costStr = "PKR " + to_string((long long)totalCost);
        r += "  *  TOTAL FARE : " + costStr + "\n";
        r += "  *  STATUS     : CONFIRMED\n";
        r += "  *                                                  *\n";
        r += "  *  HAVE A SAFE AND PLEASANT JOURNEY!              *\n";
        r += "  *                   XYZ Airlines Team             *\n";
        r += "  *                                                  *\n";
        r += "  ****************************************************\n";
        return r;
    }

    void generateTicket() const {
        ofstream outFile("ticket.txt");
        if (!outFile.is_open()) {
            cerr << "  [!] Error: Could not create ticket file.\n";
            return;
        }
        outFile << buildReceipt();
        outFile.close();
        cout << "  [✓] Ticket generated and saved to ticket.txt\n";
    }

    void displayTicket() const {
        cout << buildReceipt();
    }
};

// ────────────────────────────── Flights list ────────────────────────────────

vector<Flight> initFlights() {
    return {
        {"XY-101", "Dubai",       "3h 00m",  85000},
        {"XY-202", "Saudi Arabia","3h 30m",  95000},
        {"XY-303", "Turkey",      "6h 00m", 120000},
        {"XY-404", "UK",          "9h 30m", 175000},
        {"XY-505", "USA",         "14h 00m",210000},
        {"XY-606", "Canada",      "14h 30m",205000},
        {"XY-707", "Australia",   "12h 00m",195000},
        {"XY-808", "Europe",      "8h 00m", 155000},
        {"XY-909", "Malaysia",    "4h 30m", 110000},
        {"XY-110", "China",       "5h 00m", 115000},
        {"XY-111", "Japan",       "7h 30m", 160000},
        {"XY-112", "Singapore",   "5h 30m", 125000},
    };
}

// ─────────────────────────────── Menu ────────────────────────────────────

void displayMainMenu() {
    cout << "\n  ==========================================\n";
    cout << "             XYZ AIRLINES SYSTEM           \n";
    cout << "  ==========================================\n";
    cout << "  1. Enter Customer Details\n";
    cout << "  2. Book a Flight\n";
    cout << "  3. Generate & View Ticket\n";
    cout << "  4. Show Customer Details\n";
    cout << "  5. Exit\n";
    cout << "  ==========================================\n";

    // Show what step user is on
    cout << "  Status: ";
    if (!customerEntered)
        cout << "[Step 1: Enter customer details first]\n";
    else if (!flightBooked)
        cout << "[Step 2: Book a flight]\n";
    else
        cout << "[Step 3: Generate ticket or view details]\n";

    cout << "  Enter choice: ";
}

void showCustomerDetails(const vector<Customer>& customers) {
    if (customers.empty()) {
        cout << "  [!] No customers registered yet.\n";
        return;
    }
    string name;
    cout << "  Enter customer name to search: ";
    getline(cin, name);

    bool found = false;
    for (const auto& c : customers) {
        if (c.getName() == name) {
            c.displayDetails();
            found = true;
            break;
        }
    }
    if (!found)
        cout << "  [!] Customer \"" << name << "\" not found.\n";
}

// ──────────────────────────────── main ───────────────────────────────────────

int main() {
    vector<Customer> customers;
    vector<Flight>   flights = initFlights();
    Ticket* ticket = nullptr;
    int choice;

    do {
        displayMainMenu();

        while (!(cin >> choice)) {
            cout << "  [!] Invalid input. Enter a number (1-5): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {

            // ─────────────────── 1. Customer details ─────────────────────────
            case 1: {
                Customer customer;
                customer.enterDetails();
                customers.push_back(customer);
                customerEntered = true;
                flightBooked    = false;   // reset if re-entering
                delete ticket;
                ticket = nullptr;
                break;
            }

            // ────────────────────── 2. Book flight ───────────────────────────
            case 2: {
                if (!customerEntered) {
                    cout << "  [!] Please enter customer details first (Option 1).\n";
                    break;
                }

                cout << "\n  +------------------------------------------+\n";
                cout << "  |          AVAILABLE FLIGHTS               |\n";
                cout << "  +------------------------------------------+\n";
                for (size_t i = 0; i < flights.size(); ++i)
                    flights[i].displayFlightDetails(i + 1);
                cout << "  +------------------------------------------+\n";

                int fc;
                cout << "  Select flight (1-" << flights.size() << "): ";
                while (!(cin >> fc) || fc < 1 || fc > (int)flights.size()) {
                    cout << "  [!] Enter between 1 and " << flights.size() << ": ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                delete ticket;
                ticket = new Ticket(customers.back(), flights[fc - 1]);
                flightBooked = true;

                cout << "  [✓] Flight " << flights[fc-1].getFlightCode()
                     << " to " << flights[fc-1].getDestination()
                     << " booked for " << customers.back().getName() << ".\n";
                break;
            }

            // ──────────────── 3. Generate & view ticket ──────────────────────
            case 3: {
                if (!customerEntered) {
                    cout << "  [!] Please enter customer details first (Option 1).\n";
                    break;
                }
                if (!flightBooked) {
                    cout << "  [!] Please book a flight first (Option 2).\n";
                    break;
                }
                ticket->generateTicket();
                ticket->displayTicket();
                break;
            }

            // ───────────────────── 4. Show customer ──────────────────────────
            case 4: {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                showCustomerDetails(customers);
                break;
            }

            // ────────────────────────── 5. Exit ──────────────────────────────
            case 5:
                cout << "\n  Thank you for choosing XYZ Airlines. Goodbye!\n\n";
                break;

            default:
                cout << "  [!] Invalid choice. Select 1-5.\n";
        }

    } while (choice != 5);

    delete ticket;
    return 0;
}