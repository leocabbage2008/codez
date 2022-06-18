let mongoose = require('mongoose');
mongoose.set('debug', true);

let secretSchema = new mongoose.Schema(
  {
    id: String,
    secret: String,
  },
  { collection: 'secrets' }
);

module.exports = mongoose.model('Secret', secretSchema);
