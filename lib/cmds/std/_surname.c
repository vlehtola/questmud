/* Moved from player.c here by Nalle, Jan 2004 */

#define TP this_player()

status cmd_surname(string str)
{
 int maxlength;
 
 maxlength = 10;

 if(TP->query_wiz() 	== 5) maxlength = 70;
 if(TP->query_rebirth() >= 2) maxlength = 20;


 if (!str) 
 {
  write("Usage: surname <string>\n");
  return 1;
 }

  if(strlen(str) > maxlength && ( TP->query_wiz() != 5 ) ) 
  {
    write("Maximum length "+maxlength+" characters.\n");
    return 1;
  }

  if (str == "clear") 
  {
    write("Surname cleared.\n");
    TP->set_surname( 0 );
    return 1;
  }

  if("/daemons/editor"->ansi_check(str)) 
  {
    write("Ansi code detected. Aborted.\n");
    return 1;
  }

  if(TP->query_wiz() < 4)
     // bypassed for now // TP->set_surname(capitalize(lower_case(str)));
     TP->set_surname(str);
      else
     TP->set_surname(str);

  write("Surname set.\n");
  return 1;
}
