#define AREA_D "/daemons/area_entry_d"

make_road(int x_min, int y_min, int x_max, int y_max, string mark) {
  int x,y;
  if(x_min != x_max && y_min != y_max) {
	write("Error on "+x_min+", "+y_min+"\n");
	return;
  }
  for(y = y_min; y <= y_max; y++) {
    for(x = x_min; x <= x_max; x++) {
      AREA_D->add_road(x,y, mark);
    }
  }
  AREA_D->add_road(x_min,y_min, "+");
  AREA_D->add_road(x_max,y_max, "+");
}

load() {
  make_road(253, 97, 253, 117, "|");
  make_road(253, 117, 259, 117, "-");
  make_road(253, 117, 253, 121, "|");
  make_road(253, 121, 277, 121, "-");
  make_road(249, 94, 244, 94, "-");
  make_road(244,94, 244,80, "|");
  make_road(244,80, 234,80, "-");
  make_road(234,80, 221, 67, "/");
  make_road(221,67, 165, 67, "-");
  make_road(257,94, 267, 94, "-");
  make_road(267,94, 267, 79, "|");

  make_road(250,96, 256, 96, "#");
  make_road(250,95, 256, 95, "#");
  make_road(250,94, 256, 94, "#");
  make_road(250,93, 256, 93, "#");
  make_road(250,92, 256, 92, "#");

}

/*
Coords: 253,97 ->  253_117  (| merkki)
253,117 -> 259,117          (- merkki ja 259,117 ei + merkkid)
253,117 ->253,121           (| merkki ja kumpaankin ndihin +)
253,121 ->277_121           (- merkki ja kumpaankin ndihin +)

Coords: 249,94-> 244_94     (- merkki ja kumpaanki ndihin +)
244,94 -> 244_80            (| merkki ja kumpaanki ndihin +)
244,80 -> 234_80            (- merkki ja kumpaanki ndihin +)
234,80 -> 221_67   //mennddn SW eli / ja kumpaanki ndihin +)
221,67 -> 165_67   //W eli - merkki ja kumpaanki + merkki

257,94 -> 267_94   (- ja kumpaanki +)
267,94 -> 267_79   (| ja kumpaanki +)
More: (line 17)


# merkki ndihin
250,96->256,96
250,95->256,95
250,94->256,94
250,93->256,93
250,92->256,92

*/
