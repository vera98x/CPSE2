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


