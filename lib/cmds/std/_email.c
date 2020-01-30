/* _email.c by Nalle on the 28th of May 2002  */
/* A command for submitting your email address. */
 
cmd_email(string str) {
string tmp,tmp2;

  if(!this_player()->check_condis())  { return 1; }

  if(str)  {
  // Check for the @ sign
  if(sscanf(str,"%s@%s",tmp,tmp2)!=2)
  { write("Syntax : email [<your email>]\n"); return 1; }
  // Check for at least one . after the @ sign 
  if(sscanf(tmp2,"%s.%s",tmp,tmp2)!=2)
  { write("Syntax : email [<your email>]\n"); return 1; }      
  // Seems like it could be an OK address, thus set it
  this_player()->set_email(str);
            }

  
  tmp=this_player()->query_email();
  if(!tmp) tmp="none";
  write("Your email is set to '"+tmp+"'.\n");
  return 1;
}
