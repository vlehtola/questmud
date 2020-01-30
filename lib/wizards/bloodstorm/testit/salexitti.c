inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("bladis", "/wizards/bloodstorm/workroom.c");
  add_exit("cs",  "/world/city/cs");

  short_desc = "IHQ salaexitti huane";
  long_desc =   
 
 "dumdiduu lallalaa juu n‰in jaksa kirjotella\n"+
 "joo ja t‰h‰n viel jotain ku n‰pyttelee ni hyv‰‰ tule\n";

}
