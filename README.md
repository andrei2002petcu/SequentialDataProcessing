# Sequential Data Processing

## Functionality

The application reads a dataset consisting of *(timestamp, value)*, from terminal, and stores it in a Doubly Linked List. The processing is done according to given command line arguments.

The possible arguments are:

* `Eliminates exceptions using statistical methods`. It calculates the average and deviation to eliminate any exceptions
```
--e1
```
 
* `Noise filtering using a median filter`. It takes each set of 5 consecutive data entries and replaces the center with a new one resulted from sorting by value each set 
```
--e2
```

* `Noise filtering using average`. It takes each set of 5 consecutive data entries and replaces the center with the average from each set
```
--e3
```

* `Uniformization of the data frequency over time`. Data entries in zones with high frequency are moved to zones with a lower data frequency. If the time difference between 2 consecutive nodes is out of some given bounds, the current entry will be replaced with the average between this entry and the previous one
```
--u
```

* `Data completion`. For each interval that has a time gap greater than a given bound, the program fills in entries using a weighted average of the neighbors.
```
--c
```

* `Statistics`. Displays the number of data entries in intervals with a given length 
```
--st
```

## Notes
Formulas used for each type of processing are found in *Tema1_SD_2022.pdf*
