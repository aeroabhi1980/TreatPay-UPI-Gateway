package in.abhiworld.upigateway;

import android.app.ProgressDialog;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Base64;
import android.util.Log;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import org.apache.http.NameValuePair;
import org.apache.http.message.BasicNameValuePair;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedWriter;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLEncoder;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import javax.net.ssl.HttpsURLConnection;

public class UPIGateway extends AppCompatActivity {

    String resp = "";
    private WebView mWebView;
    URL url;
    Intent intent;
    String amount,email,e1="",iv="";
    MCrypt mcrypt;
    HttpsURLConnection con;
    JSONObject jsonObject;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main_webview);
        mWebView = findViewById(R.id.activity_gateway);
        Intent intent = getIntent();
        amount=intent.getStringExtra("amount");
        email=intent.getStringExtra("email");
        Global.amount=Double.parseDouble(amount);
        Global.email=email;

        // Enable Javascript
        mWebView.setWebViewClient(new WebViewClient());
        WebSettings webSettings = mWebView.getSettings();
        webSettings.setJavaScriptEnabled(true);
        webSettings.setAllowContentAccess(true);
        mWebView.addJavascriptInterface(new WebAppInterface(this), "ApuSDK");

        // REMOTE RESOURCE
        mWebView.loadUrl(Wrap.t5());

        // LOCAL RESOURCE
//        mWebView.loadUrl("file:///android_asset/index.html");

    }


    @Override
    public void onBackPressed() {
        Log.d("index",String.valueOf(mWebView.copyBackForwardList().getCurrentIndex()));
        Log.d("visited",String.valueOf(Global.visited));
        if (mWebView.copyBackForwardList().getCurrentIndex() > 0) {
            if(mWebView.getUrl().contains(Wrap.t4())) {
                this.finish();
//                signOut();
            } else {
                mWebView.goBack();
            }
        }
        else {
            // Your exit alert code, or alternatively line below to finish
            super.onBackPressed(); // finishes activity
        }
    }
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == 23) {
            // Process based on the data in response.
            String msg="Unknown Error";
            if(data != null)
            {
                Bundle bundle = data.getExtras();
                if (bundle != null) {
                    for (String key : bundle.keySet()) {
                        Log.d("abab", key + " : " + (bundle.get(key) != null ? bundle.get(key) : "NULL"));
                    }
                }
//            result.setText(data.getStringExtra("response"));
                String bank_ref="";
                if(!data.getStringExtra("Status").equals("FAILURE"))
                {
                    resp=data.getStringExtra("response");
                    String[] resps=resp.split("&");

                    for(int i=0;i<resps.length;i++)
                    {
                        String[] x=resps[i].split("=");
                        if(x[0].equals("Status"))
                        {
                            msg=x[1];
                        }
                        if(x[0].equals("txnId"))
                        {
                            bank_ref=x[1];
                        }
                    }
                }
                else
                {
                    msg="FAILURE";
                    try {
                        resp=data.getStringExtra("response");
                        String[] resps=resp.split("&");

                        for(int i=0;i<resps.length;i++)
                        {
                            String[] x=resps[i].split("=");
                            if(x[0].equals("Status"))
                            {
//                                msg=x[1];
                            }
                            if(x[0].equals("txnId"))
                            {
                                bank_ref=x[1];
                            }
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
                try {
                    url=new URL(Wrap.t7());

                    Long tsLong = System.currentTimeMillis()/1000;
                    String ts = tsLong.toString();
                    e1=Global.order_id+"#"+msg+"#"+bank_ref+"#"+email+"#"+ts;
                    int len=e1.length();
                    Random random=new Random();
                    iv=Wrap.r1(16);
                    mcrypt = new MCrypt(iv,Wrap.t6());
                    int index=random.nextInt(len-5)+5;
                    try {
                        e1=mcrypt.bytesToHex( mcrypt.encrypt(e1) );
                        e1= Base64.encodeToString(e1.getBytes(),Base64.DEFAULT);
                        e1=mcrypt.bytesToHex( mcrypt.encrypt(e1) );
                        Integer integer=(index+1)*(index+1);
                        e1=e1+Wrap.t8()+integer.toString();
                        String a,b;
                        a=e1.substring(0,index);
                        b=e1.substring(index);
                        e1=a+iv+b;
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                } catch (MalformedURLException e) {
                    e.printStackTrace();
                }
            }
//            Log.d("result", data.getStringExtra("response"));
            new submitResponse().execute();
//            showToast(msg);
        }
    }
    public void showToast(String toast) {
        Toast.makeText(UPIGateway.this, toast, Toast.LENGTH_LONG).show();
    }

    class submitResponse extends AsyncTask<String, String, String> {
        private ProgressDialog pDialog;
        String server_response;
        @Override
        protected void onPreExecute() {
            super.onPreExecute();
            pDialog = new ProgressDialog(UPIGateway.this);
            pDialog.setMessage("Please wait...");
            pDialog.setIndeterminate(false);
            pDialog.setCancelable(false);
            pDialog.show();
        }
        protected String doInBackground(String... args) {
            try {
                // Simulate network access.
                con = (HttpsURLConnection) url.openConnection();
                con.setRequestMethod("POST");
                con.setDoInput(true);
                con.setDoOutput(true);
                List<NameValuePair> params = new ArrayList<NameValuePair>();
                params.add(new BasicNameValuePair("e1", e1));
                OutputStream os = con.getOutputStream();
                BufferedWriter writer = new BufferedWriter(
                        new OutputStreamWriter(os, "UTF-8"));
                writer.write(getQuery(params));
                writer.flush();
                writer.close();
                os.close();

                con.connect();
                int responseCode=con.getResponseCode();
                if(responseCode == HttpsURLConnection.HTTP_OK){
                    server_response = readStream(con.getInputStream());
                    server_response = new String(mcrypt.decrypt(server_response));
                    server_response = new String(Base64.decode(server_response,Base64.DEFAULT));
                    server_response = new String(mcrypt.decrypt(server_response));
                    jsonObject=new JSONObject(server_response);
                }
            } catch (IOException e) {
                e.printStackTrace();
            } catch (JSONException e) {
                e.printStackTrace();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return null;
        }
        protected void onPostExecute(String arg) {
            // dismiss the dialog after getting all products
            // updating UI from Background Thread
            if (pDialog != null && pDialog.isShowing()) {
                pDialog.dismiss();
            }
            try {
                if (jsonObject.getString("status").equals("1")) {
                    mWebView.loadUrl(Wrap.t4()+resp+"&amount="+amount);
                }
            } catch (JSONException e) {
                e.printStackTrace();
            }
        }
    }

    private String readStream(InputStream is) {
        try {
            ByteArrayOutputStream bo = new ByteArrayOutputStream();
            int i = is.read();
            while(i != -1) {
                bo.write(i);
                i = is.read();
            }
            return bo.toString();
        } catch (IOException e) {
            return "";
        }
    }

    private String getQuery(List<NameValuePair> params) throws UnsupportedEncodingException
    {
        StringBuilder result = new StringBuilder();
        boolean first = true;

        for (NameValuePair pair : params)
        {
            if (first)
                first = false;
            else
                result.append("&");

            result.append(URLEncoder.encode(pair.getName(), "UTF-8"));
            result.append("=");
            result.append(URLEncoder.encode(pair.getValue(), "UTF-8"));
        }

        return result.toString();
    }
}
