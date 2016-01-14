/**
 * Created by 보운 on 2015-12-23.
 */

import org.apache.commons.mail.SimpleEmail;

public class Practice {
    public static void main(String[] args) {
        String emailAddress = "haioer@naver.com";

        String smtp ="smtp.naver.com";
        String port ="465";
        String isSSL="Y";
        String isAuth="Y";
        String authId="haioer";
        String authPw="rla4742*";
        String authEmail="haioer@naver.com";
        String subject = "제목";
        String message = "\r\n\r\n\r\n 내용 \r\n";
        SimpleEmail simpleEmail = new SimpleEmail();
        simpleEmail.setCharset("utf-8");
        simpleEmail.setHostName(smtp);
        if(port != null && !"".equals(port))simpleEmail.setSmtpPort(Integer.parseInt(port));
        simpleEmail.setAuthentication(authId,authPw);
        simpleEmail.setSSL(true);
        simpleEmail.setFrom(authEmail);
        simpleEmail.addTo(id);
        simpleEmail.setSubject(subject);
        simpleEmail.setMsg(message);
        simpleEmail.send();
    }
}