/* command_D  //Celtron */

/* return 1 if ansi strings detected */

int ansicheck(string s)
{
 string temp;

 if(this_player()->query_wiz()) return 0;

 if( sscanf(s,"%s"+sprintf("%c",27)+"%s",temp,temp))    return 1;
 if( sscanf(s,sprintf("%c",27)+"%s",temp) )             return 1;
 if( sscanf(s,"%s"+sprintf("%c",27),temp) )             return 1;

 return 0;
}


/*
int ansicheck(string str) {
  int itmp;
  string tmp1,tmp2;
   if(this_player()->query_wiz()) return 0;
  if(sscanf(str, "%s^[[%s", tmp1, tmp2)) return 1;
  if(sscanf(str, "%s[%dm", tmp1, itmp)) return 1;
  return 0;
}
 */

static string get_command(string cmd) {
  switch(cmd) {
  case "pc": return "party create";
  case "pi": return "party invite";
  case "pj": return "party join";
  case "plv": return "party leave";
  case "pld": return "party leader";
  case "ps": return "party status";
  case "psay": return "party say";
  case "psa": return "party shake";
  case "pf": return "party follow";
  case "pk": return "party kills";
  case "pd": return "party dice";
  case "pr": return "party report";
  case "pff": return "party force follow";
  case "la": return "look at";
  case "fi": return "finger";
  case "r": return "report";
  case "x": return "scan all";
  }
  return cmd;
}

string query_command(string cmd) {
  string tmp;
  if(sscanf(cmd, "%s %s", cmd, tmp) != 2) { }
  cmd = get_command(cmd);
  if(!cmd) return 0;
  if(!tmp) return cmd;
  return cmd+" "+tmp;
}


