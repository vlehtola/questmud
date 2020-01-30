inherit "obj/monster";

reset(arg)
{
::reset(arg);
if(arg) { return; };

set_race("human");
set_level(20);
set_gender(2);
set_name("herbalist");
set_alias("woman");
set_alt_name("Drysi");
set_short("Drysi Oakenfield the herbalist");
set_long
("Drysi the official herbalist of the city stands behind the counter smiling\n" +
"courageously. She is ready to serve the customers with superb expertise of\n" +
"different kind of plants. A long black hair, white gown decorated with flowers\n" +
"and beaming smile makes Drysi a person not easily forgotten.");
set_al(50);
set_aggressive(0);

}