inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("inn", "/world/city/inn");
  add_exit("cs",  "/world/city/cs");

  short_desc = "Shortdesc";
  long_desc = 	"The long description of your room.\n" +
		"This is a second line to demonstrate how it is made\n." +
		"And still a third final line.\n";

  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}







