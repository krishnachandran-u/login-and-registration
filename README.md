# login-and-registration
A program that incorporates a simple, non-encrypted login and registration system in C++

This program makes use of the C++ standard library fstream.
The registration process entails the creation of a dedicated 'username.txt' file, which stores the user's chosen username and password.
During the login phase, the program verifies the user's credentials by performing a comparison between the existing 'username.txt' file, if present, and the username-password combination entered by the user.
