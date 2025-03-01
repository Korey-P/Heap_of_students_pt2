# Heap_of_students_pt2

##Pseudocode

FUNCTION loadStudents(students)
    OPEN "students.csv"
    IF file cannot be opened
        PRINT "Error opening students.csv"
        RETURN
    ENDIF
    FOR each line in file
        CREATE a new Student object
        CALL student.init(line) to parse CSV data
        ADD student to students vector
    ENDFOR
    CLOSE file
    PRINT "Loaded [number] students."
END FUNCTION

FUNCTION printStudents(students)
    FOR each student in students vector
        CALL student.printStudent()
        PRINT "____________________________________"
    ENDFOR
END FUNCTION

FUNCTION showStudentNames(students)
    FOR each student in students vector
        PRINT student.getLastFirst()
    ENDFOR
END FUNCTION

FUNCTION findStudent(students)
    PRINT "Enter last name to search: "
    GET user input as searchLastName
    SET found = false
    FOR each student in students vector
        IF student.getLastFirst() contains searchLastName
            CALL student.printStudent()
            PRINT "____________________________________"
            SET found = true
        ENDIF
    ENDFOR
    IF found == false
        PRINT "No student found with last name containing [searchLastName]"
    ENDIF
END FUNCTION

FUNCTION sortStudents(students, option)
    IF option == 1 THEN  // Sort by last name
        FOR i from 0 to size of students
            FOR j from i+1 to size of students
                IF students[i].getLastFirst() > students[j].getLastFirst()
                    SWAP students[i] and students[j]
                ENDIF
            ENDFOR
        ENDFOR
    ELSE IF option == 2 THEN  // Sort by first name
        FOR i from 0 to size of students
            FOR j from i+1 to size of students
                IF students[i].getFirstName() > students[j].getFirstName()
                    SWAP students[i] and students[j]
                ENDIF
            ENDFOR
        ENDFOR
    ELSE IF option == 3 THEN  // Sort by credit hours (descending)
        FOR i from 0 to size of students
            FOR j from i+1 to size of students
                IF students[i].getCreditHours() < students[j].getCreditHours()
                    SWAP students[i] and students[j]
                ENDIF
            ENDFOR
        ENDFOR
    ENDIF
END FUNCTION

FUNCTION deleteStudents(students)
    FOR each student in students vector
        DELETE student
    ENDFOR
    CLEAR students vector
END FUNCTION

FUNCTION menu()
    PRINT "0) Quit"
    PRINT "1) Print all student names"
    PRINT "2) Print all student data"
    PRINT "3) Find a student"
    PRINT "4) Sort students"
    PRINT "Please choose 0-4: "
    GET user input as choice
    RETURN choice
END FUNCTION

FUNCTION main()
    CREATE a vector students
    CALL loadStudents(students)
    
    WHILE true
        SET choice = CALL menu()
        IF choice == "0"
            BREAK
        ELSE IF choice == "1"
            CALL showStudentNames(students)
        ELSE IF choice == "2"
            CALL printStudents(students)
        ELSE IF choice == "3"
            CALL findStudent(students)
        ELSE IF choice == "4"
            PRINT "Sort by: \n1) Last Name\n2) First Name\n3) Credit Hours (Descending)\nChoice: "
            GET user input as sortOption
            CALL sortStudents(students, sortOption)
            PRINT "Students sorted successfully."
        ELSE
            PRINT "Invalid option. Please choose again."
        ENDIF
    ENDWHILE

    CALL deleteStudents(students)
    PRINT "Program exiting. Memory cleaned up."
END FUNCTION
