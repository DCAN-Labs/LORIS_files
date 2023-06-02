# API Scripts

This folder primarily holds python files that pull data from REDCap using the API and insert them into LORIS using MySQL Connector.

## get_siblings.py

Used to handle data that the parent fills out about the child's siblings. As these are all repeat records in REDCap, a special method is needed to find the data a home in LORIS.
- Right now this script has to be run after running run.py but may be integrated in the future.

## redcap_to_loris_class.py

This file holds the class that defines the methods used to transfer data.

## run.py

This file is the script that is run to transfer data from REDCap to LORIS.
- Creates an instance of the RedcapToLoris class defined in redcap_to_loris_class.py
- Defines paramaters needed by the methods

When run it should have an output similar to the following:

    $ python run.py
    Get record HTTP Status: 200
    Get formEventMapping HTTP Status: 200
    Get metadata HTTP Status: 200
    Get report HTTP Status: 200
    Get repeatingFormsEvents HTTP Status: 200
    13 visits in visit. 13 unchanged, 0 added. 0 errors.
    336 tests in test_battery. 336 unchanged, 0 added. 0 errors.
    183 candidates in LORIS. 177 unchanged, 6 added. 0 errors.
    466 sessions in session. 463 unchanged, 3 added. 17 errors.
    468 sessions in session. 466 unchanged, 2 added. 0 errors.
    5645 entries in flag. 495 added. 0 errors.
    5645 tests in flag. 34 instrument entries updated. 34 flag entries updated. 4 errors.

## config.py

File that holds the credentials for connecting to the REDCap API and the LORIS database.
- In the .gitignore file, will need to be created following the example below

example config.py:

    config = {
        "user": "<loris database user>",
        "password": "<loris database user's password>",
        "host": "<ip address for loris database server>",
        "database": "<loris database name>"
    }
    
    token = "<token for the redcap API>"
    
    api_route = "<URL for the REDCap instance's API>"
