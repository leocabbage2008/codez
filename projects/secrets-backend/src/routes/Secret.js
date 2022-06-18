const express = require('express');
const bodyParser = require('body-parser');
const SecretModel = require('../schemas/Secret');
const dbo = require('../connection');
const Secret = require('../schemas/Secret');

const secretRouter = express.Router();
const jsonParser = bodyParser.json();

secretRouter.route('/secret').post(jsonParser, (req, res) => {
  const dbc = dbo.getDb();
  const id = req.body.id;
  const secret = req.body.secret;

  const doc = new SecretModel({
    id,
    secret,
  });

  dbc.collection('secrets').insertOne(doc, (e, result) => {
    if (e) res.status(400).send('error uploading');
    else console.log(`Added new ${result.insertedId}`);
  });

  res.json(doc);
});

secretRouter.route('/secret').get(jsonParser, async (req, res) => {
  const dbc = dbo.getDb();
  const id = req.query.id;

  const data = await dbc.collection('secrets').findOne({ id });
  res.json(data);
});

module.exports = secretRouter;
