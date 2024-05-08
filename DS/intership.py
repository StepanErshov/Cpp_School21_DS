import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Input, Conv2D, MaxPooling2D, Flatten, Dense
import os

def load_and_preprocess_image(path):
    image = tf.io.read_file(path)
    image = tf.image.decode_jpeg(image, channels=3)
    image = tf.image.resize(image, [150, 150])
    image /= 255.0 
    return image

def get_label(image_path):
    class_name = os.path.basename(os.path.dirname(image_path))
    if class_name == 'class_0':
        return 0.0 
    elif class_name == 'class_1':
        return 1.0
    else:
        return -1.0 

preprocessed_data = []
for root, dirs, files in os.walk('C:/projects/DS/generated-or-not/images'):
    for file in files:
        if file.endswith(".jpg"):
            image_path = os.path.join(root, file)
            image = load_and_preprocess_image(image_path)
            label = get_label(image_path)
            preprocessed_data.append((image, tf.constant(label, dtype=tf.float32)))

dataset = tf.data.Dataset.from_tensor_slices(preprocessed_data)

train_size = int(0.8 * len(dataset))
train_dataset = dataset.take(train_size)
test_dataset = dataset.skip(train_size)


model = Sequential()
model.add(Input(shape=(150, 150, 3, )))
model.add(Conv2D(32, (3, 3), activation='relu'))
model.add(MaxPooling2D(2, 2))
model.add(Conv2D(64, (3, 3), activation='relu'))
model.add(MaxPooling2D(2, 2))
model.add(Flatten())
model.add(Dense(512, activation='relu'))
model.add(Dense(1, activation='sigmoid'))


model.compile(loss='binary_crossentropy',
              optimizer=tf.keras.optimizers.RMSprop(learning_rate=1e-4),
              metrics=['accuracy'])

model.fit(
    train_dataset.batch(32),
    epochs=30,
    validation_data=test_dataset.batch(32),
    validation_steps=50)

predictions = model.predict(test_dataset.batch(32))