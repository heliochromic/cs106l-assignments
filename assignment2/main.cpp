/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>

std::string kYourName = "Bohdan Dyrda"; // Don't forget to change this!

std::pair<char, char> get_initials(const std::string& name) {
  std::stringstream ss(name);
  std::string first, last;
  ss >> first >> last;
  return {first[0], last[0]};
}

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::unordered_set<std::string> get_applicants(std::string filename) {
  std::ifstream file(filename);
  std::string line;

  std::unordered_set<std::string> full_names;

  while (std::getline(file, line)) {
    full_names.insert({line});
  }

  file.close();

  return full_names;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::unordered_set<std::string>& students) {
  std::queue<const std::string*> matches;

  auto [name_first, name_last] = get_initials(name);

  for (auto& student : students) {
    auto [student_first, student_last] = get_initials(student);
    if (student_first == name_first && student_last == name_last) {
      matches.push(&student);
    }
  }

  return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  return *matches.front();
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"

