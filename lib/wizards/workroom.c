inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("inn", "/world/city/inn");
  add_exit("cs",  "/world/city/cs");

  short_desc = "Shortdesc";
  long_desc = 	
 "The long description of your room, and the first line of the description. \n"+
 "This is a second line to demonstrate how it is made. And now for still a \n"+
 "third line. Remember not to make the lines over 77 chars long (without a \n"+
 "linebreak), otherwise your area will not be approved. Also see the area \n"+
 "coding rules in /AREA_OHJEET. Also learn to use the 'man' command. \n"+
 "Good luck, and remember to behave!\n";

  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}






