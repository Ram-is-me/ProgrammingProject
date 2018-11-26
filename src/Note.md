# Note

The base classes I have declared above are the general class structure for a matrix. Those who require the square symmetric matrix to perform additional functions, please add those functions to the SymmetricMatrix class so that everyone works on the same class defenitions for the matrix.

There is a need for a Record class as well as a Data Set class to be implemented so that all the other algorithms can use it. When we read from the csv, we create a DataSet structure which contains a number of records. When we want a matrix of only the numeric values, we can create one for our algorithm.

Please create a folder for your own code so that you can upload your code there.
I have an idea as to make the tasks a group of static functions defined under a class. Please suggest if you are able to come up with a better idea. (This is so that we don't need to instantiate them during the execution of the program when user provides input.)

Later on, we shall create a final Main.cpp where we will run the program so that user can interact with it.