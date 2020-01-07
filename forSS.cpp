for (int rounds = 0; rounds < 10; rounds++) {
    std::cout << "timing for sensorbuffer map: \n";

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 500; j++) {
            bufferMap[names[i]][bufferIndexMap] = result;
            bufferIndexMap++;
        }
        bufferIndexMap = 0;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    std::cout << "elapsed time: " << ((end.tv_sec - start.tv_sec) + 1e-9 * (end.tv_nsec - start.tv_nsec)) << "\n";
}


for (int rounds = 0; rounds < 10; rounds++) {
    std::cout << "timing for sensorbuffer pair: \n";
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 500; j++) {
            std::pair<char*, double> pair1;
            pair1.first = names[i];
            pair1.second = result;
            bufferPair[bufferIndexPair] = pair1;
            bufferIndexPair++;
        }
    }
    bufferIndexPair=0;
    clock_gettime(CLOCK_MONOTONIC, &end);
    std::cout << "elapsed time: " << ((end.tv_sec - start.tv_sec) + 1e-9 * (end.tv_nsec - start.tv_nsec)) << "\n";
}



    std::cout << "timing for sensorbuffer map: \n";
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    for (int rounds = 0; rounds < 10; rounds++) {
        for (int i = 0; i < bufferIndexPair; i++) {
            if (strcmp(bufferPair[i].first, "lat") == 0) {
                filteredBuffer[filteredBufferIndex] = bufferPair[i];
                filteredBufferIndex++;
            }
        }
        filteredBufferIndex = 0;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    timeresult = ((end.tv_sec - start.tv_sec) + 1e-9 * (end.tv_nsec - start.tv_nsec));
    std::cout << "elapsed time: " << timeresult << "\n";
    std::cout << "gem: " << timeresult / 10 << "\n";



void miq_movement_c::getData(sensorBuffer &buffer, int &amountSamples) { 
    struct timespec start; 
    struct timespec now; 
    clock_gettime(CLOCK_MONOTONIC, &start); 
    int ret = NO_ERROR; 
    // try to open buffer, make file descriptor 
    /* Attempt to open non blocking the access dev */ 
    int fp = open(buffer_access, O_RDONLY | O_NONBLOCK); 
    if (fp == -1) { /* TODO: If it isn't there make the node */ 
        ret = -errno; 
        fprintf(stderr, "Failed to open %s\n", buffer_access); 
        std::cout << "Failed to open buffer_access on nr" << __LINE__ << "\n"; 
        return; 
    } 
 
    int toread; 
    struct pollfd pfd = { 
        .fd = fp, 
        .events = POLLIN, 
    }; 
    // NOTE: -1 is blocking wait for event. ) is nonblocking 
    ret = poll(&pfd, 1, 0); 
    if (ret < 0) { 
        // error has take place 
        ret = -errno; 
        goto error_close_buffer_access; 
    } else if (ret == 0) { 
        // call timed out 
        goto error_close_buffer_access; 
    } 
 
    toread = buf_len; //4 
 
    //scan_size is bytes is channelsize 
    // read returns amount of bytes 
    // databytes stored in data  
    // reads the amount of bytes corresponding to toread *  
    ssize_t read_size; 
    read_size = read(fp, data, toread * scan_size); 
    clock_gettime(CLOCK_MONOTONIC, &now); 
    printf("Elapsed read bufferfile: %f\n", 
            (now.tv_sec - start.tv_sec) + 
            1e-9 * (now.tv_nsec - start.tv_nsec)); 
}



clock_gettime(CLOCK_MONOTONIC, &start); 
gps.getData(); 
clock_gettime(CLOCK_MONOTONIC, &now); 
std::cout << "elapsed: " << (now.tv_sec-start.tv_sec + 1e-9*(now.tv_nsec - start.tv_nsec)) << "\n"; 


void SecondTimer::main() {
    int intervalnano = 1000000000;
    struct timespec start;
    struct timespec now;
    struct timespec timeSpecInterval;
    int timeToSleep = 0;
    clock_gettime(CLOCK_REALTIME, &start);
    while (true) {
        clock_gettime(CLOCK_REALTIME, &now);
        // check how much time is left before one second passes. Sleep this resting time
        timeToSleep = ((intervalnano - ((now.tv_sec - start.tv_sec)*1000000000 + (now.tv_nsec - start.tv_nsec))));
        if (timeToSleep > 0 && timeToSleep < intervalnano) {
            timeSpecInterval.tv_sec = 0;
            timeSpecInterval.tv_nsec = (timeToSleep);
            nanosleep(&timeSpecInterval, NULL);
        } else {
            std::cout << "TimerError: Error!! timing is longer than one second\n";
        }
        clock_gettime(CLOCK_REALTIME, &start);
        for(auto sensor : sensors){
            sensor->setSecondFlag();
        }
        collector.setSecondFlag();
    }

}

void SecondTimer::main() {
    int intervalnano = 1000000000;
    struct timespec start;
    struct timespec now;
    struct timespec timeSpecInterval;
    int timeToSleep = 0;
    clock_gettime(CLOCK_REALTIME, &start);
    timeSpecInterval.tv_nsec = intervalnano;
    while (true) {
        clock_gettime(CLOCK_REALTIME, &start);
        nanosleep(&timeSpecInterval, NULL);
        clock_gettime(CLOCK_REALTIME, &now);
        printf("Elapsed %f\n", (now.tv_sec - start.tv_sec) + 1e-9 * (now.tv_nsec - start.tv_nsec));
    }

}

int main() {
    std::cout << " Hello World!\n";
    struct timespec start;
    struct timespec now;
    struct timespec timeSpecInterval;
    timeSpecInterval.tv_sec = 1;
    timeSpecInterval.tv_nsec = 0;
    while (true) {
        clock_gettime(CLOCK_REALTIME, &start);
        nanosleep(&timeSpecInterval, NULL);
        clock_gettime(CLOCK_REALTIME, &now);
        printf("Elapsed nanosleep %f\n", (now.tv_sec - start.tv_sec) + 1e-9 * (now.tv_nsec - start.tv_nsec));
    }

}
    

