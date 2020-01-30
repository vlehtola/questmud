make_rooms(string path,int X, int Y) {
  int x,y;
  for(x=0;x<X;x++) {
     for(y=0;y<Y;y++) {
        write("Creating "+path+"room_"+x+"_"+y+".c ... ");
        write_file(path+"room_"+x+"_"+y+".c",area_file());
        write("DONE!\n");
     }
   }
   write("ALL "+(x*y)+" CREATED!\n");
}

string area_file() {
return read_file("/wizards/gheldor/AREA_ROOM.c");
}

