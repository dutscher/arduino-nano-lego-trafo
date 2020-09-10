String createHTML(String body){
  String html =
    "<!DOCTYPE html>"
    "<html>"
    "<body>"
        "<center>"
        "" + body + ""
        "</center>"
      "</body>"
    "</html>";
return html;
}

String createHTMLYO(String body){
  String html = R"(
    <!DOCTYPE html>
    <html>
        <body>
            <center>
            ${body}
            </center>
      </body>
   </html>
   )";

   html.replace("${body}", body);
return html;
}

String createButton(String name, String method){
  String button =
    "<p>" + name + " "
      "<a href=turn" + method + " target=_blank><button>" + method +"</button></a>"
    "</p>";
  return button;
}

void setup() {
  Serial.begin(115200);
  String body = "\
    hello\
    world\
    ";
  Serial.println("");
  Serial.println(createHTML(body));
  Serial.println(createButton("ButtonName", "ButtonMethod"));
}

void loop() {

}
