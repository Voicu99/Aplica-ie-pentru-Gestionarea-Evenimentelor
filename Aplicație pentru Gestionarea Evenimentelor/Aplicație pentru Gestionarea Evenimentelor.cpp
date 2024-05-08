// Aplicație pentru Gestionarea Evenimentelor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

struct Event {
    std::string name;
    std::string date;
    std::string time;
    std::string location;
};

void addEvent(std::vector<Event>& events) {
    Event newEvent;
    std::cout << "Enter event name: ";
    std::cin >> newEvent.name;
    std::cout << "Enter event date: ";
    std::cin >> newEvent.date;
    std::cout << "Enter event time: ";
    std::cin >> newEvent.time;
    std::cout << "Enter event location: ";
    std::cin >> newEvent.location;
    events.push_back(newEvent);
    std::cout << "Event added successfully!\n";
}

void deleteEvent(std::vector<Event>& events, const std::string& eventName) {
    auto it = std::find_if(events.begin(), events.end(), [&eventName](const Event& e) { return e.name == eventName; });
    if (it != events.end()) {
        events.erase(it);
        std::cout << "Event deleted successfully!\n";
    }
    else {
        std::cout << "Event not found!\n";
    }
}

void printEvents(const std::vector<Event>& events) {
    if (events.empty()) {
        std::cout << "No events found!\n";
    }
    else {
        std::cout << "Events:\n";
        for (const auto& event : events) {
            std::cout << "Name: " << event.name << ", Date: " << event.date << ", Time: " << event.time << ", Location: " << event.location << std::endl;
        }
    }
}

int main() {
    std::vector<Event> events;
    std::string input;

    do {
        std::cout << "\n1. Add Event\n2. Delete Event\n3. Print Events\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> input;

        if (input == "1") {
            addEvent(events);
        }
        else if (input == "2") {
            std::string eventName;
            std::cout << "Enter event name to delete: ";
            std::cin >> eventName;
            deleteEvent(events, eventName);
        }
        else if (input == "3") {
            printEvents(events);
        }
        else if (input == "4") {
            std::cout << "Exiting...\n";
            break;
        }
        else {
            std::cout << "Invalid choice! Please enter a valid option.\n";
        }

        // Verificam daca utilizatorul doreste sa continue
        do {
            std::cout << "\nDo you want to continue? (yes/no): ";
            std::cin >> input;
        } while (input != "yes" && input != "no");

    } while (input == "yes");

    return 0;
}








