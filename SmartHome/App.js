import React, { useEffect, useState } from 'react';
import { View, Text, StyleSheet, TouchableOpacity } from 'react-native';
import { firebase } from '@react-native-firebase/database';

export default function App() {

  const database = firebase.app().database('https://smart-184f7-default-rtdb.asia-southeast1.firebasedatabase.app/');
  const [swit, setSwit] = useState('on');
  const pressHandler = () => {
    if (swit === 'on') {
      setSwit('off')
      database
        .ref('users/')
        .update({
          light: 0,
        })
    }
    else {
      setSwit('on')
      database
        .ref('users/')
        .update({
          light: 1,
        })

    }
  }

  return (
    <View style={styles.component}>
      <TouchableOpacity style={styles.butt} onPress={pressHandler}>
        <Text style={{ fontSize: 25 }}>
          {swit}
        </Text>
      </TouchableOpacity>
    </View>
  );
}
const styles = StyleSheet.create({
  component: {
    flex: 1,
    backgroundColor: "#fff",
    justifyContent: 'center',
    alignItems: "center",
  }
  ,
  butt: {
    backgroundColor: 'tomato',
    height: 50,
    width: 100,
    alignItems: 'center',
    justifyContent: 'center',
    borderRadius: 10,
  }
})