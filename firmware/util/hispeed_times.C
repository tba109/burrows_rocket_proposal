// Tyler Anderson 
// Wed Oct 27 22:16:14 EDT 2010
// Time for high speed readout

double speed[46] = {24.334, 23.979, 23.697, 25.638, 24.261, 23.958, 25.542, 23.853, 23.411, 24.773, 25.147,
		  24.137, 24.264, 23.748, 24.189, 24.493, 23.881, 24.111, 23.537, 23.897, 24.436, 24.233, 
		  24.358, 23.989, 23.552, 23.935, 23.990, 25.197, 24.315, 23.731, 24.193, 24.621, 23.776,
		  24.146, 23.783, 23.990, 24.340, 24.888, 24.138, 24.351, 23.660, 24.228, 24.433, 23.688, 
		  23.841, 23.675};

void hispeed_times()
{
  gStyle->SetOptStat("emr");
  TH1F * h1 = new TH1F("h1","FX2LP Bandwidth Benchmark",35,20,30);
  for(int i = 0; i < 46; i++)
    {
      h1->Fill(speed[i]);
    }
  h1->GetXaxis()->SetTitle("Bandwidth (MB/s)");
  h1->GetXaxis()->CenterTitle();
  h1->Draw();

}
