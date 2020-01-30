inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
 short_desc = "On a high mountaintop\n";
long_desc = "This is a small plateau on a high mountaintop. The wiew is incredible\n"+
              "as the black vacuum surrounds the mountain and the green and blue ground\n"+
              "opens somewhere below. there is a comfortable-looking armchair at the\n"+
              "highest point.\n";  
property = allocate(1);
  property[0] = "no_summon";
}







