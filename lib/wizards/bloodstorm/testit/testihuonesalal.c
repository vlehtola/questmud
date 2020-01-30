inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("bladis", "/wizards/bloodstorm/workroom.c");
  add_exit("cs",  "/world/city/cs");

  short_desc = "T�m� on testi huone, jossa salaexit";
  long_desc =   
 "No n�pytell��s t�h�n nytten jotain. T��l huonees vois v�h�n \n"+
 "opetella n�it� uusia juttuja mitk� on mulle viel� hieman hakusessa\n"+
 "niinkuin v�h�n kaikki viel velhona olemisessa. Salaexitti kato sit�.\n";

 
        items = allocate(2);
        items[0] = "salaexit";
        items[1] = "hieno salaexit josta voi liikkua jonnekkin muualle";

}




init() {
  ::init(); 
  add_action("liiku", "liiku"); 
}

liiku(str) {
  if(str == "salaexit") {
    write("Katoppas menit salexitist� hiphei hurraa!\n"); 
    say(this_player()->query_name()+" katosi salaexittiin hmm\n");
    this_player()->move_player("building#/wizards/bloodstorm/testit/salexitti.c");
     }
     return 1;
 }

