#define TO tell_object(ob,
string karhu;

reset(arg) {
  if(arg) return;
}
 
init() {
  add_action("karhu", "karhu");
}
 
karhu(string str) {
object ob;

if(!str) return 1;
ob=find_player(str);
if(!ob) return 1;

write("Bear sent.\n");

TO"\n"+
"            ..,,,,..          .,%%%%%,.\n"+
"          .%%%;%;%;%;%,   .,%%%%%%%,%%%%%%,.     .,,,,.\n"+
"          %%%;a@@@@@a;;,%%%%%%%%%%%%%%%%%%%%%%,;%%;%;%;%%,\n"+
"          %%%;@@@@@@a;,%%%%%%%%%%%%%%,%%%%%%%%%%;a@@@@a;%%%\n"+
"          `%%%;@@@a;,%%%%%%%%%%%%%%%%%%%%%%%%%%%%;a@@@@;%%%\n"+
"            `%%%;;,%%%%%%%%%%%%%% .%%%,%% .%%%%%%%;a@@;%%%'\n"+
"               ```%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%;%%%%'\n"+
"                 %%%%%%%%%%%%%%%%%%%'   #`%%%%%%%%%%'\n"+
"                 %%%%%%%%%%%%%%%%%%%,.  .,%%%%%%%%%%    'Hello!'\n"+
"                 %%%%%%%%%%%%%%%;a@@@@a;a@@@a;%%%%%%\n"+
"                 `%%%%%%%%%%%;a@@@a@@@@a;a@@a@a;%%%'\n"+
"                  `%%%%%%%%%;@@@a@@@a@@@;a@a@a@;%%'    ..,,.\n"+
"             ,sSSSSSs`%%%%%%%;@@@@@@@@@;a@@@@@;%'  .,%%%,;;;;,\n"+
"           .S@S;;;;;SSs %%%%%%%%%%%%%%%%%%%%%%' .,%%%%%%,;;;;;;,\n"+
"           S@@SSss;;;;sSs,s@SSSS@,sSSSSSSSSs,.%%%%%%%%%%%,;;;;;;,\n");
TO"           `S@@SSSSSSs;;Ss@@SSSS@@sSs;;;;;;S@s,%%%%%%%%%%%,;;;;;;\n"+
"           .S@@SSSSSSSSSSs@@SSSS@@sSSSSSs;;;@@S,%%%%%%%%%%%%,;;;'\n"+
"           S@@SSSSSSSSSSS'`@SSSS@s`SSSSSSSSs@S',%%%%%%%%%%%%%%'\n"+
"          %`S@SSSSSSSSS'.SSSssssSSS`SSSSSSS@S'%%,%%%%%%%%%%'\n"+
"        .%%%%,""""""%%.sSSSSS^SSSSSs%`SSSSSS'%%%%,%%%%%'\n"+
"      .%%%%%%%%%%%%.sSSSSSSS'.sSSSSS,%%"""",%%%%%%,%'\n"+
"     .%%%%%%%%%%%.sSSSSSSSS'.SSSSSSSS,%%%%%%%%%%%%%.\n"+
"    .%.%.%.%.%.%.SSSSSSSSS',SSSS^SSSSS,%,%%%%%%%%%%%\n"+
"    %;;;;;;;;;%,SSSSS^SSSS,,SSS',SSSS'%%%%%%%%%%%%%%,\n"+
"    ;;;;;;;;;;;,SSSS'%`SS';%`S'%,SS'%%%%%,%%%%%%%%%%%\n"+
"     `;;;;;;;;'%`SS'%%,S'%%%%,%,S'%%%%%%%%%%%%%%%%%%%\n"+
"              %%%`S,%%%%%%%%%%%%%%%%%%%%,%%%%%%%%%%%'\n");
TO"              ;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"+
"             .%`%%%%%%%%%%%%%%%%%%%%%%,%%%%%%%%%%%'%\n"+
"             %%%`%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%'%%%.\n"+
"            ;%%%%%`%%%%%%%%%%%%%%%%,%%%%%%%%%'%%%%%%%.\n"+
"            %%%%%%%;%:%:%:%:%%%'`%%:%:%:%:%:%%%%%%%%%%,\n"+
"            %%%%%%%%%%%%%%%%%%%. `%%%%%%%%%%%%%%%%%%%%%%,\n"+
"            %%%%%%%%%%%%%%%%%%%%   `%%%%%%%%%%%%%%%%%%%%%%,\n");
TO"            %%%%%%%%%%%%%%%%%%%%.    `%%%%%%%%%%%%%%%%%%%%%%,\n"+
"            %%%%%%%%%%%%%%%%%%%%%      `%%%%%%%%%%,%%%,%%%,%%%,\n"+
"            %%%%%%%%,%%%,%%%,%%,%.       `%%%%%,;;;;;;;;;;;;;,%,\n"+
"            `%%%%,;;;;;;;;;;;;;;,%        `%%,;;;;;;;;;;;;;;;;;;\n"+
"             `%,;;;;;;;;;;;;;;;;;;         `;;;;;;;;;;;;;;;;;;;'\n"+
"              `%;;;;;;;;;;;;;;;;;'           `;;;;;;;;;;;;;;;'\n"+
"                `;;;;;;;;;;;;;;'                ''''''''''' \n"+
"\n");



return 1;
}

short() {
  return "A bottle of KARHU";
}
 

id(str) {
  return str == "karhu";
}
 
long() {
  write("karhu <player>\n");
}


