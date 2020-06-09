package com.example.myapplication

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        sample_text.text = stringFromJNI()
        println(sample_text.text)
        println(sample_text)

        //val r = Thread { CrowStart() }
        //r.start()
        CrowStart();

        val r = Thread {
            while(true) {
                OneStep()
                Thread.sleep(1);
            }
        }
        r.start()
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String
    external fun CrowStart() : Int
    external fun OneStep() : Int

    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}

class Callback
{
    fun callback() {}
}