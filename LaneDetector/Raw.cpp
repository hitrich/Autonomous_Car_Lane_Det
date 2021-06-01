//
// Created by crypton on 01.06.2021.
//

void TimeAnalyze::Start(){

    if(debug){
        clk_start = clock();
    }
}

void TimeAnalyze::Stop(){

    if(debug){
        clk_duration = clock() - clk_start;
        clk_total += clk_duration;

        if( clk_maxtime < clk_duration )
            clk_maxtime = clk_duration;

        if(clk_mintime > clk_duration)
            clk_mintime = clk_duration;

        framecounter++;
    }
}


void TimeAnalyze::Reset(){

    if(debug){
        clk_start = 0;
        clk_total = 0;
        clk_duration = 0;
        clk_maxtime = 0;
        clk_mintime = 100 * (double)CLOCKS_PER_SEC;
        framecounter = 0;
    }
}

void TimeAnalyze::Print(){

    if(debug)
    {
        cout<<endl
            <<"TIME ANALYZE NAME: " << name         <<endl
            <<"Number of Frame: "       << framecounter <<endl
            <<"Maximum Frame Duration (s): "    << (clk_maxtime /(double) CLOCKS_PER_SEC )
            <<"\nMinumum Frame Duration (s): "  << (clk_mintime /(double) CLOCKS_PER_SEC )
            <<"\nAverage Frame Duration (s): "  << (clk_total /(double) CLOCKS_PER_SEC ) / (double) framecounter
            <<"\nTOTAL TIME (s): "  << (clk_total / (double) CLOCKS_PER_SEC)
            <<endl << "------\n";

    }
}