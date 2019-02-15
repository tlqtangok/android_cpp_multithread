package com.example.raytine.myapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;


import android.annotation.SuppressLint;
//import android.app.Activity;
//import android.os.Bundle;
//import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;
//import android.widget.Toast;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//import com.example.toast.R;



public class MainActivity extends AppCompatActivity {
    Button id_b0;
    TextView id_t0;
    int cnt = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_main);

// android:id="@+id/id_t0"
        id_b0 = (Button) findViewById(R.id.id_b0);
        id_t0 = (TextView) findViewById(R.id.id_t0);

        id_b0.setText(cnt%2 == 0? "run shell script": "back");


        id_b0.setOnClickListener(new OnClickListener() {
            @SuppressLint("SdCardPath")
            @Override
            public void onClick(View arg0) {

                String listOfFiles = "";
                listOfFiles = "go start";
                id_t0.setText(listOfFiles);
                //listOfFiles = "";


                if (1==1)
                {

                    //listOfFiles = runAsRoot();

                    id_t0.setText(cnt%2 == 0? runAsRoot():"hello world");
                    cnt++;
                    id_b0.setText(cnt%2 == 0? "run shell script": "back");

                }

            }
        });





    }


    public String runAsRoot() {

        try {
            // Executes the command.
            Process process = Runtime.getRuntime().exec("sh /data/t/run_on_phone.sh");

            // Reads stdout.
            // NOTE: You can write to stdin of the command using
            //       process.getOutputStream().
            BufferedReader reader = new BufferedReader(
                    new InputStreamReader(process.getInputStream()));

            int read;
            char[] buffer = new char[4096];
            StringBuffer output = new StringBuffer();
            while ((read = reader.read(buffer)) > 0) {
                output.append(buffer, 0, read);
            }
            reader.close();

            // Waits for the command to finish.
            process.waitFor();

            return output.toString();
        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }

}
