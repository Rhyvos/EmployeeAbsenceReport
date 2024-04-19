# Employee Absence Report

## Description
Employee Absence Report is an application designed to manage and report on employee absences. It enables loading data from CSV files, calculating absences over specified periods, and generating reports in various formats.

## Features
- Load employee and absence data from CSV files.
- Calculate absences within a specified time frame.
- Generate reports in CSV and console formats.
- Filter data according to different criteria.

## Dependencies
This project utilizes the following tools:
- CMake (version 3.15 or newer)
- Clang 18
- Google Test (for unit testing)
- Google Mock (for mocking in tests)

## Installation
To install and compile the project, follow these steps:
1. Clone the repository:
```console
git clone [REPOSITORY_URL]
cd EmployeeAbsenceReport
```
2. Configure the project using CMake:
```console
mkdir build
cd build
cmake ..
```
3. Build the project:
```console
cmake --build .
```
## Running the Application
To run the application after building, execute:
```console
./application/EmployeeAbsenceApp path/to/input.csv path/to/output.csv <from_date(dd.mm.yyy)> <to_date(dd.mm.yyy)>
```

## Testing
Run the sample tests:
```console
./tests/tests
```

## Project Structure
```bash
EmployeeAbsenceReport/
│
├── CMakeLists.txt - Main CMake configuration file.
├── application/ - Application source code.
├── business_logic/ - Application business logic.
├── data/ - Data models and their selectors.
├── loaders/ - Data loading modules.
├── report/ - Report generation module.
└── tests/ - Unit tests and mocks.
```

## License
The project is available under the GNU General Public License 3.0. See LICENSE file for more details.

## Support
If you need help using the application or want to report an issue, please contact us through [contact form/email].

## Author
Bartłomiej Nagacz - Project Creator.
