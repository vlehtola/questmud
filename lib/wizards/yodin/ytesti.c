inherit "room/room";

reset(arg)
{
if(arg) return;

        
short_desc = "Yotinin testi";
long_desc = 
"t‰m‰ on jotinin testi huone n‰‰t edess‰si ison HEVOSEN.\n" +
"sitten nurkassa seisoskelee toosi iso PATSAS\n" +
"ja vasemmalla on punainen leluauto\n" +
"voi kummastus takanasihan on ihka oikea kello joka on musta.\n"; 

items = allocate (4);
items[0] = "hevonen";
items[1] = "oi kuinka hieno ruskea heppa iiihaahhaa.\n";
items[2] = "patsas";
items[3] = "voi kummastus kun on ruma patsas ihan jotinin nakoinen kauhiata\n" +
           "kuinka joku voikaan laittaa noin ruman otuksen nurkkaan.\n";

}
