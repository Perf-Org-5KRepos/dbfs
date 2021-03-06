//****************************************************************************
//      Copyright (c) Microsoft Corporation. All rights reserved.
//      Licensed under the MIT license.
//
// File: helper.h
//
// Purpose:
//   This file contains the declarations of helper functions used by
//   sqlfs and SQLQuery.
//
#pragma once

#define SUCCESS                 0
#define FAILURE                 1
#define DEFAULT_PERMISSIONS     0777
#define LINUX_PATH_DELIM        "/"

// This method concatenates the dump directory path to the provided 
// relative path.
//
string
CalculateDumpPath(
    string path);

// This method prints the ERRNO error string along with the function that 
// caused the error and a custom string that is passed.
//
int
ReturnErrnoAndPrintError(
    const char* func,
    string error_str);

// This method prints error message provided if verbose mode is enabled 
// either on STDERR or the log file depending on whether the log file
// paramater was passed at startup.
//
void
PrintMsg(const char* format, ...);

// This method gets the server details like  hostname/IP, 
// username, password and version for a given server name.
//
void
GetServerDetails(
    string servername,
    string& hostname,
    string& username,
    string& password);

// This method creates a file with write permissions. Or truncates to zero
// if one already exists.
//
void
CreateFile(
    const char* path);

// This checks if the file pointed to by the provided path is a
// dbfs file (created by this tool).
//
bool
IsDbfsFile(
    const char* path);

// This method creates the empty DMV files and custom query files for a given server.
// The virtual location of the files (as seen) is <MOUNT DIR>/<SERVER NAME>/.
//
void
CreateDbfsFiles(
    const string& servername,
    const string& hostname,
    const string& username,
    const string& password,
    const int version);

// This method exits the program and in doing so the function DestroySQLFs
// is called.
//
void
KillSelf();

// Given a server name, get ServerInfo.
//
ServerInfo* GetServerInfo(
    const string& servername);

// Given a server name, get the user specified custom query directory.
//
string GetUserCustomQueryPath(
    const string& servername);