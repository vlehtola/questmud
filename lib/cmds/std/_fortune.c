// Linux fortunes. -- Nalle December 2003

#define FORTUNE_D "/daemons/fortune/fortune"

cmd_fortune(str) 
{
 string categories;
 int i;

 categories = "";

 if(str == "help")
  write("Syntax : fortune [ category ]\n");

 if(str == "help" || str == "categories")
   {
    for(i = 0; i < sizeof( FORTUNE_D->query_categories() ); i++)
        categories += FORTUNE_D->query_categories()[i] + ", ";

    write("Possible categories are "+categories[0 .. strlen(categories)-3]+".\n");
    return 1;
   }

 if(!str || member_array(str, FORTUNE_D->query_categories()) == -1 )
   {
    write( FORTUNE_D -> give_fortune() );
    return 1;
   }

 // Asked for a specific category
 if( member_array(str, FORTUNE_D->query_categories()) != -1)
   {
    write( FORTUNE_D -> give_fortune( str ) );
    return 1;
   }

}
