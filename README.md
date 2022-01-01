# Sierra_Environment
First Rendition of Static Factory Design Method for developing
studies and more using C++ for ACSIL in Sierra Chart


###### ACSIL STUDY DEV TEMPLATE

### SierraChart Custom Study development template implementing
static factory design pattern with a controller->model->view flow


What Still needs done is figuring out class wide pointers, so that 
references to user inputs, chart data, and setting subgraph refs
can be done nice and neatly, such that the data we need/want can
be set as public/private as needed. And all functions in a class
will have access to that data.

This is hugely crucial in the user setting of what feature groups
to calculate and what target variables will be. 


Besides figuring out what I assume is a smart pointer, the file
imports need cleaned up so duplicate copies of things dont happen!!
