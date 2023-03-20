import './App.css';
import React, { useState } from 'react';
import Modal from './components/Modal';
import { v4 as uuidv4 } from 'uuid';
import API from './api.js';

function App() {
  const [secret, setSecret] = useState('');
  const [id, setId] = useState('');
  const [getter, setGetter] = useState('');
  const [vis0, setVis0] = useState(false);
  const [vis1, setVis1] = useState(false);
  const [modalContent0, setModalContent0] = useState('');
  const [modalContent1, setModalContent1] = useState('');
  const [secretText, setSecretText] = useState('');
  const changeSecret = (e) => {
    if (!vis0) {
      setSecret(e.target.value);
    } else {
      setSecret('');
    }
  };
  const changeGetterId = (e) => {
    if (!vis1) {
      setGetter(e.target.value);
    } else {
      setGetter('');
    }
  };
  const handleCreateSubmit = (e) => {
    if (secret) {
      const callback = async () => {
        const random = uuidv4();
        const response = await API.post('/secret', { id: random, secret });
        console.log(response.data);
        setId(random);
        setModalContent0('Your code is: ' + random);
        setVis0(true);
        setSecret('');
      };
      callback();
    } else {
      setModalContent0('Enter your secret.');
      setVis0(true);
    }
    e.preventDefault();
  };
  const handleGetSubmit = (e) => {
    if (getter) {
      const callback = async () => {
        const response = await API.get('/secret', { params: { id: getter } });
        console.log(response.data);
        setModalContent1(response.data.secret);
        setSecretText(response.data.secret);
        setVis1(true);
        setGetter('');
      };
      callback();
    } else {
      setModalContent1('Enter a code.');
      setVis1(true);
    }
    e.preventDefault();
  };
  return (
    <div className='body'>
      <span className='header'>SECRETS</span>
      <div className='content'>
        <div className='form'>
          {id ? (
            <div className='code'>
              <span>click to copy</span>
              <span>↓</span>
              <span>
                <button
                  className='buttonAsText'
                  onClick={() => {
                    navigator.clipboard.writeText(id);
                    setModalContent0('Successfully copied.');
                    setVis0(true);
                  }}
                  tabIndex={vis0 ? '-1' : '1'}
                >
                  CODE: {id && id}
                </button>
              </span>
            </div>
          ) : (
            <span>ENTER SECRET: </span>
          )}
          <form onSubmit={(e) => handleCreateSubmit(e)}>
            <input
              value={secret}
              onChange={changeSecret}
              tabIndex={vis0 ? '-1' : '1'}
            />
            <button type='submit' tabIndex={vis0 ? '-1' : '1'}>
              Submit
            </button>
          </form>
          <Modal vis={vis0} setVis={setVis0} content={modalContent0} />
        </div>
        <div>
          {secretText ? <span>{secretText}</span> : <span>GET SECRET: </span>}
          <form onSubmit={(e) => handleGetSubmit(e)}>
            <input
              value={getter}
              onChange={changeGetterId}
              tabIndex={vis0 ? '-1' : '1'}
            />
            <button type='submit' tabIndex={vis0 ? '-1' : '1'}>
              Submit
            </button>
          </form>
          <Modal vis={vis1} setVis={setVis1} content={modalContent1} />
        </div>
      </div>
    </div>
  );
}

export default App;
